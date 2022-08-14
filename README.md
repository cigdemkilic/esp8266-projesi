# esp8266-projesi
ESP8266 ESP-12E Geliştirme Kartı ile hx711 ve hdt11 sensörünü kullarak geliştirdiğim ve internete çıktığım bir proje çalışması.

Özet
 Biliyoruz ki petshoplar havasız ortamlardır. Alan dar ve hayvan sayısı fazladır. Bu durum hayvanların hayatlarını tehlikeye atabilir.
 Örneğin tavşanlar bir kaç hava deliği olan cam fanuslarda barındırılıyor. Ve bir süre sonra fanusların içerisi havasız kalır. 
 Sıcaklık ve nem değerleri tehlikeli boyutlarda değişiklik gösterebilir. Düşük nemli ortamlarda virüs ve bakteriler çoğalırken, yüksek nemli ortamlarda mantarlar çoğalır.
 Bu durum hayvanların hayatlarını tehlikeye sokabilir. Hastalıklar, vsvs. Yine yüksek sıcaklık veya düşük sıcaklık da aynı şekilde hayvanlar için tehlikeli durumlardır.
 
 Bu durumların önüne geçebilmemiz için önce haberdar olmamız gerekir. Proje de bunu sağlıyor.
 Kullandığım Hdt11 sensörü sayesinde ortamdaki sıcaklık ve nem seviyesini ölçebiliyorum. Sıcaklık ve nem değeri optimum seviye değerinin altında veya üstünde bir değer çıkarsa uyarı mesajı veriyorum, aynı zamanda ledi de yakarak ekrana bakmadan görülebilen bir uyarı sağlıyorum.
 Yine petshoplarda çok fazla hayvan olduğu durumlarda yem ve su miktarının kontrolü zorlaşabilir, gözden de kaçabilir.
 Yaptığım projede bunu da kontrol ediyorum. HX711 ağırlık sensörü kullanıyorum. Yem miktarı belirlediğimiz seviyenin altına düştüğünde uyarı veriyor.
 
 
![a6c245f2-bc8e-4090-baa6-e637c96923b3](https://user-images.githubusercontent.com/75319816/184551992-e9a5260b-a24e-455a-80b3-d3b584ece4e2.jpg)
