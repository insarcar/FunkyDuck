hostedPlugin = loadAudioPlugin("C:\Program Files\Common Files\VST3\TSGen.vst3");
hostedPlugin.DisplayMode = 'Parameters';
setParameter(hostedPlugin,'Active', 1);
setParameter(hostedPlugin, 'Frequency 1', 0.5);
setParameter(hostedPlugin, 'Frequency 2', 0.55);
setParameter(hostedPlugin, 'Frequency 3', 0.6);
setParameter(hostedPlugin, 'Signal type', 0/11); %% n-esima scelta --> n/11
dispParameter(hostedPlugin);

disp(getParameter(hostedPlugin, 'Active'));

fs = 96000;
dt = 1/fs;
time1 = 0;
time2 = 0.5/2;
time3 = 1.5/2;
time4 = 1.55/2;
time5 = 2.605/2;
time6 = 2.625/2;
time7 = 2.8/2;
time8 = 3.0/2;
time9 = 3.2/2;
time10 = 3.205/2;
time11 = 4/2;
time12 = 4.855/2;
time13 = 5/2;

samples = time13 * fs;

t1 = (time1:dt:time2);
t2 = (time2:dt:time3);
t3 = (time3:dt:time4);
t4 = (time4:dt:time5);
t5 = (time5:dt:time6);
t6 = (time6:dt:time7);
t7 = (time7:dt:time8);
t8 = (time8:dt:time9);
t9 = (time9:dt:time10);
t10 = (time10:dt:time11);
t11 = (time11:dt:time12);
t12 = (time12:dt:time13);

x1 = transpose(zeros(size(t1)));
x2 = transpose(zeros(size(t2)));
x3 = transpose(zeros(size(t3)));
x4 = transpose(zeros(size(t4)));
x5 = transpose(zeros(size(t5)));
x6 = transpose(zeros(size(t6)));
x7 = transpose(zeros(size(t7)));
x8 = transpose(zeros(size(t8)));
x9 = transpose(zeros(size(t9)));
x10 = transpose(zeros(size(t10)));
x11 = transpose(zeros(size(t11)));
x12 = transpose(zeros(size(t12)));

hostedPlugin.setMaxSamplesPerFrame(480012);

x2 = process(hostedPlugin, x2);
x4 = process(hostedPlugin, x4) ./ 2;
x6 = process(hostedPlugin, x6) ./ 4;
x7 = process(hostedPlugin, x7);
x10 = process(hostedPlugin, x10) ./ 2;
x11 = process(hostedPlugin, x11) ./ 6;


X = [x1;x2;x3;x4;x5;x6;x7;x8;x9;x10;x11;x12];
%disp(length(X));

outputFile = 'TestSignal.wav';
audiowrite(outputFile,X,fs,'BitsPerSample',32);


clear