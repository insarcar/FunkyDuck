function [Y, factor, GRed, atks, rels, env, plot_thresh, knees] = comp(X, SC, sr, params)

    %parametri impliciti
    [threshold, slope] = paramsImplicit(params(2));

    plot_thresh = db2mag(threshold);

    ms2smp = 0.001 * sr; 
    SC = mean(SC,2);
    
    % risoluzione follower
    res = ceil(10 * ms2smp);
    
    %%fattori di transienti e inviluppi
    switch params(1)

        case 0

            vu = ClassicFollower(SC, res);
            env = RMSFollower(SC, res);
            factor = CrestFactor(vu, env, sr);

        case 1

            type = 0;
            [env, factor, ~] = CoBE(SC, res, sr, type);

        case 2

            type = 1;
            [env, factor, ~] = CoBE(SC, res, sr, type);

    end
    %%gain computer
    [GRed, knees] = tFunc(env, threshold, slope, params(6), sr);
    
    %%ar filter
    [GRed, atks, rels] = atkrel(GRed, factor, ms2smp, params(4), params(5));
    
    %%gain control
    Y = bsxfun(@times,X,GRed);
    %makeup
    Y = Y .* db2mag(params(3));
    %softclip
    Y = softClip(Y, 1.0, 1);


end
