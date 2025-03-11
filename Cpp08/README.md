# CPP Module 08: Templated Containers, İteratörler ve Algoritmalar

Bu modül, C++'ta şablon kullanımını, STL containerlerini, iteratörleri ve algoritmaları derinlemesine incelememizi sağlar. Modern C++ projelerinde sıklıkla kullanılan bu yapıların etkili kullanımı, performanslı ve sürdürülebilir kodlar yazmanızda önemli rol oynayacaktır.

## Modüle Genel Bakış

Bu modül, C++ Standard Template Library (STL) içindeki temel veri yapılarını ve algoritmalarını kullanarak, gerçek dünya problemlerini çözmeye yönelik çeşitli uygulamalar geliştirmenizi hedefler. Özellikle şablon programlama (template programming) ve container'ların işleyişini daha iyi anlamanızı sağlayacak üç temel egzersiz içerir.

## Egzersizler

### Egzersiz 00: Easy Find

Bu egzersiz, şablon programlamanın temellerini ve STL container'larını kullanmayı öğretmeyi amaçlar.

#### Gereksinimler:
- `easyfind` adlı bir şablon fonksiyonu oluşturmalısınız.
- Fonksiyon iki parametre alacaktır:
  - T tipinde bir container (integer değerler içeren)
  - Bir integer değeri
- Fonksiyon, container içinde verilen integer değerin ilk bulunduğu yeri tespit etmelidir.
- Eğer değer bulunamazsa, bir exception fırlatmalı veya uygun bir hata değeri döndürmelisiniz.

#### Uygulama İpuçları:
- STL algoritmaları (`std::find` gibi) kullanabilirsiniz.
- Container türlerinin davranışlarını inceleyerek, en uygun hata yönetim stratejisini belirleyin.
- Fonksiyonunuzu farklı container tipleriyle (vector, list, deque vs.) test etmeyi unutmayın.
- İlişkisel (associative) container'ları ele almanız gerekmiyor.

### Egzersiz 01: Span

Bu egzersiz, dinamik veri yönetimi ve algoritma uygulamasını öğretmeyi amaçlar.

#### Gereksinimler:
- `Span` adlı bir sınıf oluşturmalısınız.
- Constructor, maksimum N adet integer'ı saklayabilecek bir yapı oluşturmalı (N, unsigned int olarak verilir).
- `addNumber()` metodu ile tekil sayılar eklenebilmeli.
- Eğer zaten N sayı depolanmışken yeni bir sayı eklenmeye çalışılırsa, exception fırlatılmalı.
- `shortestSpan()` ve `longestSpan()` metotları, depolanan sayılar arasındaki en kısa ve en uzun mesafeyi hesaplayıp döndürmeli.
- Eğer sayı yoksa veya sadece bir sayı varsa, mesafe hesaplanamayacağından exception fırlatılmalı.
- Sınıfınızı en az 10.000 sayı ile test etmelisiniz.
- Çok sayıda elemanı tek seferde eklemek için bir iteratör aralığını kabul eden ek bir metot eklemelisiniz.

#### Uygulama İpuçları:
- İç veri yapısı olarak `std::vector` kullanabilirsiniz.
- Mesafe hesaplamalarında, STL algoritmaları (`std::sort`, `std::adjacent_difference` gibi) yardımcı olabilir.
- İteratör aralığı kullanarak ekleme için `template` yapısı düşünün.


### Egzersiz 02: Mutated Abomination

Bu egzersiz, STL container'larını genişletme ve iteratör kavramını derinlemesine anlama konusunda sizi eğitir.

#### Gereksinimler:
- `MutantStack` adlı bir sınıf oluşturmalısınız.
- Bu sınıf, `std::stack` sınıfını temel almalı ve tüm fonksiyonlarını sağlamalı.
- Ek olarak, standard stack'te olmayan bir özellik ekleyeceksiniz: iteratörler.
- Stack içeriğinde gezinebilmek için `begin()` ve `end()` metotlarını uygulamalısınız.

#### Uygulama İpuçları:
- `std::stack` içinde kullanılan temel container'a erişmek için kalıtım ve composition yapılarını kullanın.
- `typedef` veya `using` ile iteratör tiplerini tanımlayın.
- İteratör uygulamanızı test etmek için kod örneğini çalıştırın ve sonuçları doğrulayın.


## Bellek Yönetimi ve Verimlilik

STL containerlerini kullanırken bellek yönetimi ve performans önemli faktörlerdir:

### Sürekli vs Sürekli Olmayan Bellek

- **Sürekli Bellek (Contiguous Memory)**: Yüksek performanslı rastgele erişim için idealdir, CPU önbelleğiyle daha verimli çalışır.
- **Sürekli Olmayan Bellek (Non-Contiguous Memory)**: Daha esnek bir yapı sunar, özellikle sık ekleme/çıkarma işlemlerinde avantajlıdır.

### Amortize Edilmiş O(1) Kavramı

Amortize edilmiş O(1), bir işlemin bazı durumlarda O(n) sürebilmesine rağmen, uzun vadede ortalama O(1) sürede tamamlanacağını gösterir:

```
Örneğin std::vector'un büyüme stratejisinde:
- İlk ekleme: 1 yer ayır (O(1))
- İkinci ekleme: Kapasiteyi 2'ye çıkar, kopyalama maliyeti O(1)
- Üçüncü ekleme: Kapasiteyi 4'e çıkar, kopyalama maliyeti O(2)
- Dördüncü ekleme: Kapasiteyi 8'e çıkar, kopyalama maliyeti O(4)
...
```

Bu büyüme stratejisi sayesinde, toplam n eleman eklemek için yapılan işlem maliyeti O(n) olurken, tek bir ekleme işleminin ortalama maliyeti O(1) olur.

## Container Adaptörleri

Container adaptörleri, mevcut STL containerlerini kullanarak özel davranışlar sergileyen yeni veri yapıları oluşturur:

### Yapısı ve Çalışma Prensibi

- Container adaptörleri, arka planda başka bir containerı kullanır (varsayılan olarak genellikle `std::deque`).
- Adaptörler, temel containerın tüm işlevselliğini sunmaz, sadece belirli işlemleri (örneğin `push`, `pop`) sağlar.
- İç containerı erişmek için `this->c` şeklinde kullanım yapılır.

### `typename` Anahtar Kelimesi ve Neden Önemli

`typename` anahtar kelimesi, şablon programlamada büyük önem taşır:

```cpp
template <typename T, typename Container = std::deque<T>>
class MyStack {
    typedef typename Container::value_type value_type;
    typedef typename Container::iterator iterator;
    // ...
};
```

Burada `typename` kullanmanın amacı, derleyiciye `Container::value_type` ifadesinin bir tür (type) olduğunu belirtmektir. Aksi takdirde, derleyici bunun bir değişken veya statik üye olabileceğini düşünebilir.

## Kaynaklar

- [C++ Standard Library](https://en.cppreference.com/w/cpp/container)
- [Medium - C++ 5.Bölüm](https://medium.com/@sensoyyasin72/c-5-b%C3%B6l%C3%BCm-127baa2a074b)
