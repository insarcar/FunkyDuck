x = linspace(-2,2,201).';

y = slim(x, 1.0, 1);

plot (x,y);
hold on
plot (x,x)
hold off
grid on
xlabel 'Ampiezza del segnale in entrata'
ylabel 'Ampiezza del segnale in uscita'
print('-bestfit','-dpdf','soft_clip.pdf')

function y = slim(x,l, hardness)

    ord = hardness * 2 + 1;
    cmp = ord - 1;

    r = cmp / (ord * l);

    x = r * x;

    y = x - x.^ord / ord;
    y(x<-1) = -cmp/ord;
    y(x>1) = cmp/ord;

    y = y / r;

end