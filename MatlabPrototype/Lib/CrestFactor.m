function [ C ] = CrestFactor(env_vu, env_rms, sr)

    C = env_vu ./ env_rms;
%     cutoff = 1 / 0.04;
%     fc = cutoff / (2 * sr); 
%     [b,a] = butter(2, fc, "high");
%     C = filter(b,a,C);
    %scaling
    for i = 1 : length(C)
        C(i) = C(i) + 1;
        C(i) = log10(C(i)) * 3;
        C(i) = C(i) ^ 2;
        C(i) = max(C(i), 1);
        C(i) = min(C(i), 6);
    end
   

    
end