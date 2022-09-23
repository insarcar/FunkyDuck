function [ pGR, atks, rels ] = atkrel( GR, factor, ms2smp, sensitivity, instrument)
    %% auto attack, release basato sull'indicatore usato per i transienti
    
    min_atk = 40; %%ms
    min_rel = 80; %%ms
    max_atk = 100; %%ms
    max_rel = 240;%%ms
    
    if(instrument ~= 0)
        min_atk = min_atk + 20; %%ms
        min_rel = min_rel + 40; %%ms
        max_atk = max_atk + 20; %%ms
        max_rel = max_rel + 40; %%ms
    end

    L = length(GR);
    pGR = zeros(size(GR));
    pGR(1) = GR(1);
    atks = zeros(size(GR));
    rels = zeros(size(GR));
    atks(1) = min_atk;
    rels(1) = min_rel;
    
    w = max(sensitivity, 0) * 2;
	ts = max((abs(sensitivity) ^ 1.5) * 10, 1);
    for i = 2:L    

		ex = factor(i) ^ (2 * -sensitivity);

		atk = max_atk * w + min_atk * (1 - w);
		rel = max_rel * w + min_rel * (1 - w);

		atk = (atk / ts) * ex;
		rel = (rel / ts) * ex;

        %%disp(atk);
        atks(i) = atk;
        rels(i) = rel;

        atk = exp(-1 / (atk * ms2smp));
        rel = exp(-1 / (rel * ms2smp));

        atk = atk * pGR(i - 1) + (1 - atk) * GR(i);
        rel = rel * pGR(i - 1) + (1 - rel) * GR(i);

        if GR(i) < pGR(i - 1)
            pGR(i) = atk;
        else
            pGR(i) = rel;
        end

    end
    
end
    