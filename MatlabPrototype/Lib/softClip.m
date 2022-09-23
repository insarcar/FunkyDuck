function Y = softClip(X,l,hardness)

    ord = hardness * 2 + 1;
    cmp = ord - 1;

    r = cmp / (ord * l);

    X = r * X;

    Y = X - X.^ord / ord;
    Y(X<-1) = -cmp/ord;
    Y(X>1) = cmp/ord;

    Y = Y / r;

end