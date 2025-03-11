# C++ Module 02

## Ad-hoc Polimorfizm, Operatör Aşırı Yükleme ve Ortodoks Kanonik Sınıf Formu

Bu modül, C++'da ad-hoc polimorfizmi, operatör aşırı yüklemelerini ve ortodoks kanonik sınıf formunu anlamanıza yardımcı olmak için tasarlanmıştır. Modül kapsamında sabit noktalı sayıları (fixed-point numbers) uygulamaya çalışacağız.

## İçerik

- [Exercise 00: Ortodoks Kanonik Formda İlk Sınıfım](#exercise-00-ortodoks-kanonik-formda-i̇lk-sınıfım)
- [Exercise 01: Daha Kullanışlı Bir Sabit Noktalı Sayı Sınıfına Doğru](#exercise-01-daha-kullanışlı-bir-sabit-noktalı-sayı-sınıfına-doğru)
- [Exercise 02: Şimdi Konuşuyoruz](#exercise-02-şimdi-konuşuyoruz)
- [Önemli Kavramlar](#önemli-kavramlar)
- [Kaynaklar](#kaynaklar)

## Exercise 00: Ortodoks Kanonik Formda İlk Sınıfım

Bu alıştırmada, sabit noktalı sayıları temsil eden ve ortodoks kanonik forma uygun bir sınıf oluşturmanız gerekiyor.

### Gereksinimler

- **Özel (Private) Üyeler:**
  - Sabit noktalı sayı değerini saklamak için bir tamsayı
  - Kesirli bitlerin sayısını saklamak için statik bir sabit tamsayı (her zaman 8 olacak)

- **Genel (Public) Üyeler:**
  - Sabit noktalı sayı değerini 0'a başlatan varsayılan bir kurucu
  - Bir kopya kurucusu (copy constructor)
  - Bir kopya atama operatörü aşırı yüklemesi (copy assignment operator)
  - Bir yıkıcı (destructor)
  - `int getRawBits(void) const;` fonksiyonu - sabit noktalı değerin ham değerini döndürür
  - `void setRawBits(int const raw);` fonksiyonu - sabit noktalı sayının ham değerini ayarlar

## Exercise 01: Daha Kullanışlı Bir Sabit Noktalı Sayı Sınıfına Doğru

Bu alıştırmada, Exercise 00'daki sınıfınızı daha işlevsel hale getirmeniz gerekiyor.

### Ek Gereksinimler

- **Yeni Kurucular:**
  - Parametre olarak sabit bir tamsayı alan bir kurucu
  - Parametre olarak sabit bir kayan noktalı sayı alan bir kurucu

- **Yeni Üye Fonksiyonlar:**
  - `float toFloat(void) const;` - sabit noktalı değeri kayan noktalı değere dönüştürür
  - `int toInt(void) const;` - sabit noktalı değeri tamsayı değerine dönüştürür

- **Operatör Aşırı Yükleme:**
  - Çıkış akışına sabit noktalı sayının kayan noktalı gösterimini ekleyen ekleme operatörü (`<<`) aşırı yüklemesi

## Exercise 02: Şimdi Konuşuyoruz

Bu alıştırmada, sabit noktalı sayı sınıfınızı çeşitli operatörlerle genişletmeniz gerekiyor.

### Ek Gereksinimler

- **Karşılaştırma Operatörleri:**
  - `>`, `<`, `>=`, `<=`, `==`, `!=`

- **Aritmetik Operatörler:**
  - `+`, `-`, `*`, `/`

- **Artırma/Azaltma Operatörleri:**
  - Ön-artırma, son-artırma, ön-azaltma, son-azaltma

- **Statik Üye Fonksiyonlar:**
  - İki sabit noktalı sayı referansı alan ve en küçüğünü döndüren `min` fonksiyonu
  - İki sabit sabit noktalı sayı referansı alan ve en küçüğünü döndüren `min` fonksiyonu
  - İki sabit noktalı sayı referansı alan ve en büyüğünü döndüren `max` fonksiyonu
  - İki sabit sabit noktalı sayı referansı alan ve en büyüğünü döndüren `max` fonksiyonu

## Önemli Kavramlar

### Ortodoks Kanonik Form

Ortodoks Kanonik Form (Orthodox Canonical Class Form), bir C++ sınıfının aşağıdaki dört özel üyeye sahip olması gereken standart bir formdur:

1. Varsayılan kurucu (Default constructor)
2. Kopya kurucusu (Copy constructor)
3. Kopya atama operatörü (Copy assignment operator)
4. Yıkıcı (Destructor)

### Varsayılan Copy Constructor ve Tanımlı Copy Constructor Farkı

#### Varsayılan Copy Constructor:
- Üyelerin adreslerini veya değerlerini birebir kopyalar (shallow copy).
- Dinamik bellek kullanılan sınıflarda iki nesnenin aynı adresi paylaşmasına yol açabilir.
- Yıkıcı (destructor) çağrıldığında çift silme (double delete) hatası oluşabilir.
- Eğer sınıfta yalnızca temel veri türleri (int, float, char, vs.) varsa, varsayılan kopyalama doğru çalışır.

#### Tanımlı Copy Constructor:
- Üyelerin derin kopyasını (deep copy) yapar.
- Dinamik olarak tahsis edilen belleği yeniler ve eski nesneden bağımsız hale getirir.

### Yüzeysel Kopya (Shallow Copy) vs. Derin Kopya (Deep Copy)

#### Yüzeysel Kopya (Shallow Copy):
- İlk nesne üzerinden farklı bir nesne oluşturulur fakat nesne içerisindeki değerler ilk nesne içerisindeki değerlerin bellek referansları aynı olacak şekilde kopyalanır.
- Örneğin: `Human b(a)` şeklinde default constructor ile tanımlama olduğunda yüzeysel kopya yapılır.
- Yıkıcı (destructor) çağrıldığında double free hatası oluşabilir.
- `b.data = 73;` dediğinizde a'nın da değeri değişir çünkü birbirlerinin referansıdırlar ve aynı bellek adresini gösterirler.

#### Derin Kopya (Deep Copy):
- Nesnenin değerleri ve tamamının içerikleri ile kopyalanması ve yeni bellek referansı oluşturulmasını sağlar.
- Kopya üzerindeki nesneler farklı bellek referanslarını işaret edeceği için kopya nesne üzerinde yapılan değişiklikler ilk nesneyi etkilemez.

### Sabit Noktalı Sayılar (Fixed-Point Numbers)

Sabit noktalı sayılar, kayan noktalı sayılara alternatif olarak kullanılan bir sayı temsil biçimidir ve şu avantajları sağlar:

- Performans avantajı
- Oyun motorları, dijital ses işleme, sinyal işleme gibi alanlarda kullanılır
- Kesirli sayıları işlemek için hızlı ve verimli bir yöntem sağlar

#### Örnek:

**Tamsayı (42) için dönüşüm:**
```
Fixed Point Value = 42 << 8 (8 bit sola kaydırma) = 42 * 2^8 = 42 * 256 = 10752
```

Geri dönüşüm:
```
10752 / 256 = 42
```

**Kesirli Sayı (42.73) için dönüşüm:**
```
42.73 * 256 = 10938.88 (Yuvarlama ile 10939 veya 10938)
```

Geri dönüşüm:
```
10938 / 256 = 42.7265625
```

Burada hassasiyet kaybı olduğunu görebilirsiniz (42.73 yerine 42.7265625).

## Kaynaklar

### Genel
- [Copy Constructor in C++](https://www.geeksforgeeks.org/copy-constructor-in-cpp)
- [Operator Overloading in C++](https://www.geeksforgeeks.org/operator-overloading-cpp/)
- [Orthodox Canonical Class Form](https://riceset.com/C++/Understanding-the-Orthodox-Canonical-Class-Form)

### Sabit Noktalı ve Kayan Noktalı Sayılar
- [Sabit Noktalı ve Kayan Noktalı Gösterime Genel Bakış](https://medium.com/@melisaceylan/sabit-noktal%C4%B1-ve-kayan-noktal%C4%B1-g%C3%B6sterime-genel-bak%C4%B1%C5%9F-98418f26ad10)
- [IEEE Standard 754 Floating Point Numbers](https://www.geeksforgeeks.org/ieee-standard-754-floating-point-numbers/)
- [Kayan Noktalı Sayılar](http://talhakum.com/2017-01-04-kayan-noktali-sayilar)

### Operatör Aşırı Yükleme
- [Increment and Decrement Operator Overloading in C++](https://www.geeksforgeeks.org/increment-and-decrement-operator-overloading-in-c/)