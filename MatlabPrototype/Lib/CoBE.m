function [ E, B, EBF ] = CoBE(X, res, sr, type)
%% outputs a scaled and filtered brightness descriptor, equivalent brigthness pitch, and the reveal envelope
%% the core CoBE algorythm was developed by G.Presti, D.Mauro, G.Haus at Laboratorio di Informatica Musicale in University of Milan

    if(type == 0)
        Follower = @RMSFollower;
        scale = 10;
    else
        Follower = @ClassicFollower;
        scale = 5;
    end
    %algoritmo CoBE
    
    %reveal envelope
    E = Follower(X, res);
    %reveal filtered envelope
    dX = diff( [0; X] );
    Ed = Follower(dX, res);
    %calcolo CoBE
    B = Ed./E;
    %gestione NaN
    B(isnan(B)) = 2;
    %calcolo EBF
    EBF = (sr/pi).*asin(B./2);
    
    %%butter hp
    cutoff = 1 / 0.04;
    fc = cutoff / (2 * sr); 
    [b,a] = butter(2, fc, "high");
    B = filter(b,a,B);
    
    %scaling   
    for i = 1 : length(B)
        B(i) = max(0, B(i));
        B(i) = B(i) * scale;
        B(i) = B(i) + 1;
        B(i) = min(B(i), 6);
    end
end

