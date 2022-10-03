addpath('Lib');
addpath('sounds');
f1 = "TestSignal.wav";
f2 = "snare.wav";

[SC, sr] = audioread(f1);
ms2smp = 0.001 * sr; 
SC = mean(SC,2);    
res = ceil(10 * ms2smp);

vu = ClassicFollower(SC, res);
env = RMSFollower(SC, res);
c = CrestFactor(vu, env, sr);

type = 0;
[env, r, ~] = CoBE(SC, res, sr, type);

type = 1;
[env, p, ~] = CoBE(SC, res, sr, type);

Z = [1:1:length(SC)] ./ sr;
figure;
t = tiledlayout(4,1);

h(1) = nexttile(t, 1);
plot(Z, SC); title 'signal';
grid on

h(2) = nexttile(t, 2);
plot(Z, c); title 'crest factor';
grid on

h(3) = nexttile(t, 3);
plot(Z, r); title 'CoBE RMS';

h(4) = nexttile(t, 4);
plot(Z, p); title 'CoBE peak';
grid on
linkaxes(h, 'x');
xlim([Z(1), Z(end)]);

print('-fillpage','-dpdf','sine_test.pdf');

[SC, sr] = audioread(f2);
SC = mean(SC,2);    

vu = ClassicFollower(SC, res);
env = RMSFollower(SC, res);
c = CrestFactor(vu, env, sr);

type = 0;
[env, r, ~] = CoBE(SC, res, sr, type);

type = 1;
[env, p, ~] = CoBE(SC, res, sr, type);

Z = [1:1:length(SC)] ./ sr;
figure;
t = tiledlayout(4,1);

h(1) = nexttile(t, 1);
plot(Z, SC); title 'signal';
grid on

h(2) = nexttile(t, 2);
plot(Z, c); title 'crest factor';
grid on

h(3) = nexttile(t, 3);
plot(Z, r); title 'CoBE RMS';

h(4) = nexttile(t, 4);
plot(Z, p); title 'CoBE peak';
grid on
linkaxes(h, 'x');
xlim([Z(1), Z(end)]);

print('-fillpage','-dpdf','snare_test.pdf');
