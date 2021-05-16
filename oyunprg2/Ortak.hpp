#pragma once
#include <iostream>


/*UYARI!!!!!!!!!!!!!!!!!!:
Visual Studio derleyicisi ile çalýþýrken mutlak adres ile çalýþmak zorunda kaldým. Göreceli adresi 
derleyici üzerinden açamýyor. Bu yüzden geliþtirme aþamasýnda derleyicide mutlak adresi kullandým resimler için.
Göreceli adres exenin bulunduðu klasörden exeyi açýnca sorunsuz çalýþmaktadýr. IDE üzerinden uygulamayý çalýþtýrmak
için alttaki mutlak adreslerin yorumlarýný deðiþtirebilirsiniz.

Saygýlarýmla.
*/


//tüm dosya yolu deðiþkenleri sondan eklemelidir. örneðin path + yeni path hesaplanýrken
//path "...klasor\\resimler\\" iken yeni path "baskabirklasor\\baskaresimler\\ þeklindedir."


//static sf::String assets_loc = "resimler\\";
static sf::String assets_loc = "C:\\Users\\murat\\source\\repos\\dependencies\\bin\\resimler\\";
