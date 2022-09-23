function [GR, knees] = tFunc(envelope, threshold, slope, kneemode, sr)
%%calcolo della funzione di trasferimento del compressore, comprende
%%calcolo automatico del parametro di knee
    envelope = max(abs(envelope), 10^-6);
    L = length(envelope);
    knees = zeros(size(envelope));
    GR = zeros(size(envelope));

    switch kneemode

        case 0 %hard

            for i = 1:L
            overshoot = mag2db(envelope(i)) - threshold;
               
                if (overshoot > 0)
                    GR(i) = db2mag(overshoot * slope);
                else 
                    GR(i) = 1;
                end
            
            end

        case 1 %soft

            knee = 12;
            knees(knees == 0) = knee;

            for i = 1:L
                overshoot = mag2db(envelope(i)) - threshold;
                kneeHalf = knee / 2;
                
                if (overshoot > kneeHalf)
                    GR(i) = db2mag(overshoot * slope);
                elseif (overshoot > -kneeHalf && overshoot < kneeHalf)
                    GR(i) = db2mag(0.5 * slope * ((overshoot + kneeHalf) ^ 2 / knee));
                else 
                    GR(i) = 1;
                end
            
            end

        case 2 %auto

            estimate = (slope * threshold) / 2;

            time = 0.04;%%modifica questa 
            
            alpha = exp(-1 / (time * sr)); 
        
            dev = zeros(size(envelope));
        
            c = mag2db(envelope(1)) * slope / 2;
            dev(1) = (1 - alpha) * (c - estimate);
            knee = (dev(1) + estimate) / 2;
            knees(1) = knee;
          
            kneeHalf = knee / 2;
            overshoot = mag2db(envelope(1)) - threshold;
            if (overshoot > kneeHalf)
                GR(1) = db2mag(overshoot * slope);
            elseif (overshoot > -kneeHalf && overshoot < kneeHalf)
                GR(1) = db2mag(0.5 * slope * ((overshoot + kneeHalf) ^ 2 / knee));
            else 
                GR(1) = 1;
            
            end
            
            
            
            for i = 2:L
                overshoot = mag2db(envelope(i)) - threshold;
                c = mag2db(envelope(i)) * slope / 2;
                dev(i) = alpha * dev(i - 1) + (1 - alpha) * (c - estimate);
                knee = (dev(i) + estimate) / 2;
                knees(i) = knee;
        
                kneeHalf = knee / 2;
        
                 if (overshoot > kneeHalf)
                    GR(i) = db2mag(overshoot * slope);
                elseif (overshoot > -kneeHalf && overshoot < kneeHalf)
                    GR(i) = db2mag(0.5 * slope * ((overshoot + kneeHalf) ^ 2 / knee));
                else GR(i) = 1;
                end
            
            end

    end
end