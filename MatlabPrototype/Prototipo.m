addpath('Lib');
addpath('sounds')

%%PARAMETERS ----------------------------
factorSwitch = 1;                           %% 0 per crest, 1 per rms cobe, 2 per peak cobe
compression = 1;                            %%[0,1]
level = 0;                                  %%[0,1]
sensitivity = -0.5;                          %%[-0.5,0.5] decimal, negative = fast costants, positive = tight constants, 0 = default
instrument = 0;                             %% 0 guitar, 1 bass
kneemode = 2;                               %% 0 hard, 1 soft (12dB), 2 auto
%%----------------------------------------

%input file select
groove = 'groove1.wav';
if (instrument ~=0)
    groove = 'bass1.wav';
end

%output file name
compTypes = {'crest','cobe','cobe'};
envTypes = {'rms', 'rms', 'peak'};
kneeModes = {'hardknee', 'softknee', 'autoknee'};
compType = compTypes{factorSwitch + 1};
envType = envTypes{factorSwitch + 1};
knee = kneeModes{kneemode + 1};
if sensitivity > 0
    scale = 'scalepositive';
elseif sensitivity < 0
    scale = 'scalenegative';
else
    scale = 'zeroscale';
end
inputFile  = groove;
keyFile    = inputFile;
outputFile = [inputFile(1:end-4),'_',compType,'_',envType,'_', knee,'_',scale,'.wav'];

%read and process
params = [factorSwitch, compression * 12, level * 12, sensitivity, instrument, kneemode]; %%input to comp
[X, srx] = audioread(inputFile);
[SC, sr] = audioread(keyFile);
[Y, factor, GRed, atks, rels, env, plot_thresh, knees] = comp(X, SC, sr, params);

%write file
audiowrite(outputFile,Y,sr,'BitsPerSample',32);


%%----------plots
Z = [1:1:length(X)] ./ sr;
figure;
t = tiledlayout(5,1);

h(1) = nexttile(t, 1);
plot(Z,X), title 'signal';
hold on
plot(Z,Y);
plot([Z(1), Z(end)], [plot_thresh, plot_thresh], '--r', 'LineWidth', 2);
plot(Z, env, 'LineWidth', 2);
hold off
grid on

h(2) = nexttile(t, 2);
plot(Z, GRed); title 'post filter GR';
grid on

h(3) = nexttile(t, 3);
plot(Z, factor); title 'transient factor';
grid on

h(4) = nexttile(t, 4);
plot(Z,atks,"Color", 'b'); title 'time constants (ms)';
hold on
plot(Z,rels,"Color", 'r');
hold off
grid on

h(5) = nexttile(t, 5);
plot(Z, knees); title 'knees';
grid on

linkaxes(h, 'x');
xlim([Z(1), Z(end)]);

clear
