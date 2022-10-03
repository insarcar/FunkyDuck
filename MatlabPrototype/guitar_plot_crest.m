addpath('Lib');
addpath('sounds');

%%PARAMETERS ----------------------------
factorSwitch = 0;                           %% 0 per crest, 1 per rms cobe, 2 per peak cobe
compression = 0.85;                            %%[0,1]
level = 0;                                  %%[0,1]
sensitivity = -.43;                          %%[-0.5,0.5] decimal, negative = fast costants, positive = tight constants, 0 = default
instrument = 0;                             %% 0 guitar, 1 bass
kneemode = 2;                               %% 0 hard, 1 soft (12dB), 2 auto
%%----------------------------------------

groove = 'groove3.wav';
inputFile  = groove;
keyFile    = inputFile;

params = [factorSwitch, compression * 12, level * 12, sensitivity, instrument, kneemode]; %%input to comp
[X, srx] = audioread(inputFile);
[SC, sr] = audioread(keyFile);
[Y, factor, GRed, atks, rels, env, plot_thresh, knees] = comp(X, SC, sr, params);
sensitivity = .43;
params = [factorSwitch, compression * 12, level * 12, sensitivity, instrument, kneemode]; %%input to comp
[Y1, factor1, GRed1, atks1, rels1, env1, plot_thresh, knees] = comp(X, SC, sr, params);

Z = [1:1:length(Y)] ./ sr;
figure;
t = tiledlayout(7,1);

h(1) = nexttile(t, 1);
plot(Z,X), title 'signal(negative)';
hold on
plot(Z,Y);
plot([Z(1), Z(end)], [plot_thresh, plot_thresh], '--r', 'LineWidth', 2);
plot(Z, env, 'LineWidth', 2);
hold off
grid on

h(2) = nexttile(t, 2);
plot(Z,X), title 'signal(positive)';
hold on
plot(Z,Y1);
plot([Z(1), Z(end)], [plot_thresh, plot_thresh], '--r', 'LineWidth', 2);
plot(Z, env1, 'LineWidth', 2);
hold off
grid on

h(3) = nexttile(t, 3);
plot(Z, GRed, "Color", 'b'); title 'post filter GR, blue = negative, red = positive';
hold on
plot(Z, GRed1, "Color", 'r')
hold off
grid on

h(4) = nexttile(t, 4);
plot(Z, factor); title 'transient factor';
grid on

h(5) = nexttile(t, 5);
plot(Z,atks,"Color", 'b'); title 'time constants (ms) (negative)';
hold on
plot(Z,rels,"Color", 'r');
hold off
grid on

h(6) = nexttile(t, 6);
plot(Z,atks1,"Color", 'b'); title 'time constants (ms) (positive)';
hold on
plot(Z,rels1,"Color", 'r');
hold off
grid on

h(7) = nexttile(t, 7);
plot(Z, knees); title 'knees';
grid on

linkaxes(h, 'x');
xlim([Z(Z==0.45), Z(Z==2.05)]);

print('-fillpage','-dpdf','guitar_crest.pdf')

clear