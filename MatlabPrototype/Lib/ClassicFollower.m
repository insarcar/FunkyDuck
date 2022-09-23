function [ E ] = ClassicFollower( X, release )
%%Peak Envelope follower
    alpha = exp(-1/release);
    L = size(X,1);
    E = zeros(size(X));
    X = abs(X);
    E(1) = abs(X(1));
    for n = 2:L
        E(n) = max( X(n) , E(n-1) * alpha );
    end

end

