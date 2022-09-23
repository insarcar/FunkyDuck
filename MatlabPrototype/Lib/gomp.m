
x = [1:5000];
cutoff = 1 / 0.04;
fc = cutoff / (2 * 44100); 
[b,a] = butter(2, fc, "high");
C = mag2db(filter(b,a,x));
%     a = -0.99999; b = -15; c = -0.55;
%     gom = mag2db(1 + a * exp(b * exp(c * x)));
%     disp(gom);
% 
    figure
    plot(x, C)
    grid on
    xlabel('hZ')
    ylabel('dB')
