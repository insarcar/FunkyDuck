function [ Y ] = RMSFollower( X, windowsize )
%RMS Envelope Follwer
    
    %gestione dei NaN
    X(isnan(X))=0;
    %array ausiliario
    Z = [X; zeros(0,1)];
    
    %window
    W = zeros(windowsize,1);
    
    Z = (Z.^2)/windowsize;
    Y = zeros(size(Z));
    
    Y(1) = Z(1);
    %calcolo RMS
    for i = 2:size(X)
        j = mod(i-1,windowsize)+1;
        old = W(j);
        new  = Z(i);
        Y(i) = Y(i-1)-old+new;
        W(j) = new;
    end;
    %per evitare radici complesse
    Y(Y<0) = 0;
    Y = Y.^0.5;
    
    % silence = 0.002;
    % Y(Y<silence) = 0;
    
    % [B,A]=butter(1,1/windowsize);
    % Y=filtfilt(B,A,Y);
end

