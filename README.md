# dualDerivative / automatskoDiferenciranje
-auomatskoDiferencirnanje: prilikom racunanja f(a) kao nuspojavu dobijemo i f'(a)  
-dualni brojevi: a + bɛ, gdje je ɛ != 0 && ɛ^2 = 0  
-izvedu se pravila racunanja s njima(za operatore +,- itd)  
Neka imamo funkciju f koja je diferecijabilna u tacki a.  
Ako trazimo vrijednost njenog izvoda u toj tacki, ponudimo joj kao argument  
dualni broj a + bɛ i razvijemo je u Taylorov red pri cemu cemo dobiti sljedecu relaciju:  
f(a + bɛ) = f(a) + f'(a)bɛ  
Da bi izracunali f(a) i f'(a) samo obavimo racunanje izraza funkcije f nad dualnim brojem a + ɛ
