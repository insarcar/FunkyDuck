function [threshold, slope] = paramsImplicit(compLevel)
%trasformazione dei parametri espliciti nei parametri impliciti interni
    
    %level [0, 12] ---> threshold [0dB, -28dB circa] negative gompertz
    a = -0.999999; b = -15; c = -0.55;
    threshold = 1 + a * exp(b * exp(c * compLevel));
    threshold = mag2db(threshold);

    % level [0, 12] --> ratio [1, 10] linear
    ratio = compLevel * 0.75 + 1; 
    slope = 1/(ratio) - 1 ;

end