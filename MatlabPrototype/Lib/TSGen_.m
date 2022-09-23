
fs = 96000;
dt = 1/fs;
time1 = 1;
time2 = 3;
time3 = 4;
t1 = (0:dt:time1);
t2 = (time1:dt:time2);
t3 = (time2:dt:time3);

fc = 440;

x1 = 1/4*cos(2*pi*fc*t1);
x2 = cos(2*pi*fc*t2);
x3 = 1/4*cos(2*pi*fc*t3);

x = [x1, x2, x3 ; x1, x2, x3];
x = transpose(x);
t = [t1, t2, t3];

outputFile = 'TestSignal_.wav';
audiowrite(outputFile,x,fs,'BitsPerSample',32);
clear