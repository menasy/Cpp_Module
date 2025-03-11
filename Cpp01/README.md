# CPP Module 01

## Bellek Ayırma, Üye İşaretçileri, Referanslar ve Switch İfadeleri

Bu modül, C++'ta bellek yönetimi, işaretçiler, referanslar ve switch ifadeleri gibi temel kavramların derinlemesine anlaşılmasını sağlamak üzere tasarlanmıştır. Her bir alıştırma, bu kavramları pratik uygulamalarla pekiştirmeme olanak tanıdı.

## İçerik

Bu modül altı egzersizden oluşmaktadır:

1. [ex00: BraiiiiiiinnnzzzZ](#exercise-00-braiiiiiinnnnzzzzz)
2. [ex01: Moar brainz!](#exercise-01-moar-brainz)
3. [ex02: HI THIS IS BRAIN](#exercise-02-hi-this-is-brain)
4. [ex03: Unnecessary violence](#exercise-03-unnecessary-violence)
5. [ex04: Sed is for losers](#exercise-04-sed-is-for-losers)
6. [ex05: Harl 2.0](#exercise-05-harl-20)
7. [ex06: Harl filter](#exercise-06-harl-filter)

## Kazanılan Beceriler

- Stack ve heap bellek ayrımı ve kullanımı
- `new` ve `delete` operatörleri ile dinamik bellek yönetimi
- İşaretçiler ve referanslar arasındaki farklar
- Sınıf üyelerine işaretçilerin kullanımı
- C++ dosya işlemleri ve string manipülasyonu
- Switch-case yapısı ve etkin kullanımı

## Exercise 00: BraiiiiiiinnnzzzZ

### Proje Açıklaması

Bu alıştırma, basit bir Zombie sınıfı oluşturmayı ve zombilerin stack ve heap üzerinde nasıl oluşturulduğunu anlamayı amaçlar.

### Yapılanlar

- `Zombie` sınıfı oluşturuldu (private `name` değişkeni ve `announce()` metodu)
- `newZombie()` fonksiyonu ile heap'te zombie oluşturma
- `randomChump()` fonksiyonu ile stack'te zombie oluşturma
- Zombilerin uygun şekilde yok edilmesi

### Öğrenilen Konseptler

- Stack ve heap arasındaki farklar
- Dinamik bellek tahsisi (`new` operatörü)
- Bellek serbest bırakma (`delete` operatörü)
- Nesne scope'u ve yaşam süresi

## Exercise 01: Moar brainz!

### Proje Açıklaması

Bu alıştırma, tek bir bellek tahsisi ile birden fazla Zombie nesnesi oluşturmayı öğretmeyi amaçlar.

### Yapılanlar

- `zombieHorde()` fonksiyonunun implementasyonu
- Tek bir bellek tahsisi ile N zombie oluşturma
- Her zombie'ye aynı ismin verilmesi
- Oluşturulan zombie'lerin hepsinin `announce()` metodunu çağırma
- Bellek sızıntılarını önlemek için uygun temizleme

### Öğrenilen Konseptler

- Dinamik dizi oluşturma
- Çoklu nesne tahsisi
- Bellek yönetimi ve sızıntı kontrolü

## Exercise 02: HI THIS IS BRAIN

### Proje Açıklaması

Bu alıştırma, işaretçiler ve referanslar arasındaki farkı anlamayı amaçlar.

### Yapılanlar

- Bir string değişkeni oluşturma: "HI THIS IS BRAIN"
- Bu değişkene bir işaretçi tanımlama: `stringPTR`
- Bu değişkene bir referans tanımlama: `stringREF`
- Değişkenin, işaretçinin ve referansın bellek adreslerini yazdırma
- Değişkenin değerini, işaretçi ve referans aracılığıyla yazdırma

### Öğrenilen Konseptler

- İşaretçiler ve referanslar arasındaki farklar
- Bellek adresleri ve işlemleri
- Referansların, işaretçilerin alternatif bir sözdizimi olduğunu anlama

## Exercise 03: Unnecessary violence

### Proje Açıklaması

Bu alıştırma, bir sınıfın üyesi olarak başka bir sınıfı işaretçi veya referans olarak kullanmanın farkını anlamayı amaçlar.

### Yapılanlar

- `Weapon` sınıfının oluşturulması (private `type` değişkeni, `getType()` ve `setType()` metodları)
- `HumanA` sınıfının oluşturulması (referans olarak bir `Weapon` kullanır)
- `HumanB` sınıfının oluşturulması (işaretçi olarak bir `Weapon` kullanır)
- Her iki insan sınıfının da `attack()` metodu ile silahını kullanabilmesi

### Öğrenilen Konseptler

- Üye değişkenlerde referans ve işaretçi kullanımı
- Nesne oluşturma zamanında referans başlatmanın önemi
- İşaretçilerin null olabileceği durumları yönetme

## Exercise 04: Sed is for losers

### Proje Açıklaması

Bu alıştırma, bir dosyadaki tüm belirli string'leri başka bir string ile değiştiren bir program oluşturmayı amaçlar.

### Yapılanlar

- Dosya açma ve okuma işlemleri
- String arama ve değiştirme mantığı (std::string::replace kullanmadan)
- Sonuçları yeni bir dosyaya yazma

### Öğrenilen Konseptler

- C++ dosya işlemleri (`std::ifstream`, `std::ofstream`)
- String manipülasyonu
- Hata kontrolü ve yönetimi

## Exercise 05: Harl 2.0

### Proje Açıklaması

Bu alıştırma, üye fonksiyonlara işaretçileri kullanarak bir şikayet sistemi oluşturmayı amaçlar.

### Yapılanlar

- `Harl` sınıfının oluşturulması
- Dört farklı şikayet seviyesi için private fonksiyonlar: `debug()`, `info()`, `warning()`, `error()`
- Belirli bir seviyedeki şikayeti göstermek için `complain()` metodu
- İç içe if/else yapıları yerine üye fonksiyonlara işaretçiler kullanımı

### Öğrenilen Konseptler

- Üye fonksiyonlara işaretçiler
- Fonksiyon işaretçileri dizileri
- Fonksiyonel programlama yaklaşımı

## Exercise 06: Harl filter

### Proje Açıklaması

Bu alıştırma, switch-case yapısını kullanarak belirli bir seviyenin üzerindeki tüm şikayetleri filtrelemeyi amaçlar.

### Yapılanlar

- Exercise 05'teki `Harl` sınıfını genişletme
- Komut satırı argümanı olarak bir şikayet seviyesi alma
- Bu seviye ve üzerindeki tüm şikayetleri görüntüleme
- İç içe if/else yapıları yerine switch-case kullanımı

### Öğrenilen Konseptler

- Switch-case yapısının etkin kullanımı
- Enum ve switch-case kombinasyonu
- Komut satırı argümanlarını işleme

## Derleme ve Çalıştırma

Her alıştırma için bir Makefile bulunmaktadır. Alıştırmaları derlemek için:

```bash
cd ex00 (veya ex01, ex02, ...)
make
```

Programları çalıştırmak için (örnek olarak):

```bash
./zombie
./zombieHorde
./brain
./violence
./replace [dosya_adı] [değiştirilecek_string] [yeni_string]
./harl [DEBUG/INFO/WARNING/ERROR]
./harlFilter [DEBUG/INFO/WARNING/ERROR]
```

## Zorluklar ve Çözümler

- **Challenge 1**: Stack ve heap belleğin kullanımı arasındaki farkı anlama.
  - **Çözüm**: Zombie örneği ile stack'in otomatik bellek yönetimi ve heap'in manuel bellek yönetimi gerektirdiğini gözlemledim.

- **Challenge 2**: Referans ve işaretçi arasındaki farkı anlama.
  - **Çözüm**: HumanA ve HumanB sınıfları arasındaki farkları inceleyerek referansların her zaman geçerli bir nesneyi göstermesi gerektiğini, işaretçilerin ise NULL olabileceğini öğrendim.

- **Challenge 3**: Üye fonksiyonlara işaretçilerin kullanımı.
  - **Çözüm**: Harl sınıfında bir işaretçi dizisi ve fonksiyon ismini indekse eşleyen bir mekanizma oluşturarak if/else yapılarından kaçındım.

## Sonuç

CPP Module 01, bellek yönetimi, işaretçiler ve referanslar arasındaki farklar, üye fonksiyonlara işaretçiler ve switch-case yapısının kullanımı gibi C++'ın temel kavramlarını derinlemesine anlamama yardımcı oldu. Bu alıştırmalar, teorik bilgiyi pratik uygulamalarla pekiştirerek, daha karmaşık C++ projelerine temel oluşturdu.