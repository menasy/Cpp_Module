# CPP Module 00

## Namespaces, Classes, Member Functions, stdio Streams, Initialization Lists, Static, Const, and Basic C++ Concepts

Bu modül, C++'ın temel konseptlerini öğrenmek için tasarlanmış bir dizi alıştırmadan oluşmaktadır. Bu projede, C tarzı programlamadan C++ tarzı programlamaya geçiş yaparak nesne yönelimli programlamanın (OOP) temel prensiplerini uygulamayı öğrendim.

## İçerik

Bu modül üç alıştırmadan oluşmaktadır:

1. [ex00: Megaphone](#exercise-00-megaphone)
2. [ex01: My Awesome PhoneBook](#exercise-01-my-awesome-phonebook)
3. [ex02: The Job Of Your Dreams](#exercise-02-the-job-of-your-dreams)

## Kazanılan Beceriler

- C++ sınıfları ve nesneleri ile çalışma
- Üye fonksiyonlarının uygulanması
- Namespacelerin kullanımı
- Standart giriş/çıkış akışlarının (iostream) kullanımı
- Static ve const anahtar kelimelerinin kullanımı
- Header dosyaları ve implementasyon dosyalarının ayrılması
- Makefile kullanımı
- Sınıfların private ve public bölümlerinin uygun şekilde tasarlanması

## Exercise 00: Megaphone

### Proje Açıklaması

Bu alıştırmada, komut satırı argümanlarını alan ve onları büyük harfle yazdıran basit bir program geliştirdim. Program aşağıdaki işlevleri yerine getiriyor:

- Verilen tüm argümanları büyük harfe çevirerek yazdırır
- Argüman verilmediğinde "* LOUD AND UNBEARABLE FEEDBACK NOISE *" yazdırır
- Birden fazla argüman verildiğinde tümünü birleştirip büyük harfle yazdırır

### Öğrenilen Konseptler

- `std::cout` ile standart çıktı işlemleri
- `std::string` sınıfının kullanımı
- String manipülasyonu (`toupper()` fonksiyonu)
- Komut satırı argümanlarının işlenmesi

## Exercise 01: My Awesome PhoneBook

### Proje Açıklaması

Bu alıştırmada, basit bir telefon rehberi uygulaması geliştirdim. Program, kullanıcıya rehbere kişi ekleme, kişileri listeleme ve arama gibi temel işlevler sunar.

Projede iki ana sınıf uyguladım:
- `PhoneBook`: Kişi kayıtlarını tutan sınıf (maksimum 8 kişi)
- `Contact`: Her bir kişinin bilgilerini tutan sınıf

### Özellikler

- Maksimum 8 kişi saklayabilir (9. kişi eklendiğinde en eski kişi silinir)
- Üç komut kabul eder: ADD, SEARCH ve EXIT
- ADD: Yeni bir kişi ekler (ad, soyad, lakap, telefon numarası ve en karanlık sır alanlarını doldurur)
- SEARCH: Kayıtlı kişileri listeler ve indeks ile belirli bir kişinin detaylarını gösterir
- EXIT: Programdan çıkar

### Öğrenilen Konseptler

- Sınıf tanımlama ve nesneleri oluşturma
- Getter ve setter metodları
- Private ve public erişim belirleyicileri
- Kullanıcı girdisi alma ve doğrulama
- Veri görüntüleme formatlaması (`std::setw`, `std::right` vb.)
- Header ve implementasyon dosyalarının ayrılması

## Exercise 02: The Job Of Your Dreams

### Proje Açıklaması

Bu alıştırmada, eksik bir dosyayı (Account.cpp) yeniden oluşturmak için çalıştım. Bana verilen Account.hpp header dosyası ve bir log dosyası kullanarak, Account sınıfının implementasyonunu yeniden oluşturdum.

### Öğrenilen Konseptler

- Tersine mühendislik (var olan çıktı ve header dosyasından implementasyonu çıkarma)
- Static üye değişkenleri ve metodları
- Sınıf constructor ve destructorları
- Fonksiyonların prototipleri ve implementasyonları arasındaki ilişki
- Timestamp formatlaması

## Derleme ve Çalıştırma

Her alıştırma için bir Makefile bulunmaktadır. Alıştırmaları derlemek için:

```bash
cd ex00 (veya ex01, ex02)
make
```

Programları çalıştırmak için:

```bash
./megaphone "Hello World"
./phonebook
./account
```

## Zorluklar ve Çözümler

- **Challenge 1**: Sınıf tasarımını doğru şekilde yapmak.
  - **Çözüm**: Private olması gereken üye değişkenlerini ve public olması gereken metodları doğru şekilde ayırdım.

- **Challenge 2**: PhoneBook'ta maksimum 8 kişi saklama ve yeni kişi eklendiğinde en eski kişiyi silme.
  - **Çözüm**: Dairesel bir tampon (circular buffer) mantığını kullanarak en eski kişiyi takip eden bir sayaç uyguladım.

- **Challenge 3**: Account.cpp dosyasını log dosyasından yeniden oluşturmak.
  - **Çözüm**: Log dosyasındaki çıktıları analiz ederek, her metodun nasıl çalışması gerektiğini anladım ve buna göre implementasyonu gerçekleştirdim.

## Sonuç

CPP Module 00, C++ programlama dilinin temel konseptlerini anlamak ve uygulamak için mükemmel bir başlangıç oldu. Nesne yönelimli programlamanın temel prensiplerini, sınıfların nasıl tasarlanacağını ve C++'ın temel kütüphanelerinin nasıl kullanılacağını öğrendim. Bu modül, ilerleyen C++ modülleri için sağlam bir temel oluşturdu.