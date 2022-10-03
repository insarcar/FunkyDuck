
x = [0:12];

a = -0.99999; b = -15; c = -0.55;
gom = mag2db(1 + a * exp(b * exp(c * x)));

figure
plot(x, gom)
grid on
xlabel('Compression')
ylabel('Threshold in dB')
print('-bestfit','-dpdf','gomp.pdf')