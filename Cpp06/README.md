# CPP06 - C++ Cast ve Tür Dönüşümleri

## İçerik
Bu repo, C++'ta tür dönüşümleri, serileştirme ve dinamik tür tanıma konularını içeren üç alıştırmadan oluşmaktadır. C++'ın farklı cast operatörleri ve bunların kullanım alanları incelenmektedir.

## Alıştırmalar

### Ex00: Skaler Tiplerin Dönüşümü
`ScalarConverter` sınıfı, string formatında verilen C++ literal değerlerini işleyerek farklı skaler tiplere (char, int, float, double) dönüştürür. Bu sınıf, kullanıcılar tarafından örneklenemez ve yalnızca statik bir `convert` metodu içerir.

Desteklenen literal tipleri:
- Karakter literalleri: 'c', 'a' vb.
- Tam sayı literalleri: 0, -42, 42 vb.
- Float literalleri: 0.0f, -4.2f, 4.2f, -inff, +inff, nanf
- Double literalleri: 0.0, -4.2, 4.2, -inf, +inf, nan

Program, verilen stringin tipini tespit eder, gerçek tipine dönüştürür ve ardından diğer tiplere açık dönüşüm yapar. Dönüşüm mantıksız veya taşma durumunda ise kullanıcıya uygun bir mesaj gösterilir.

**Örnek Çıktılar:**
```
./convert 0
char: Non displayable
int: 0
float: 0.0f
double: 0.0

./convert nan
char: impossible
int: impossible
float: nanf
double: nan

./convert 42.0f
char: '*'
int: 42
float: 42.0f
double: 42.0
```

### Ex01: Serileştirme
`Serializer` sınıfı, veri işaretçilerini serileştirme ve deserileştirme işlemlerini gerçekleştirir. Bu sınıf da kullanıcılar tarafından örneklenemez ve şu statik metotları içerir:

- `uintptr_t serialize(Data* ptr)`: Bir işaretçiyi unsigned integer tipine dönüştürür.
- `Data* deserialize(uintptr_t raw)`: Unsigned integer değerini Data işaretçisine dönüştürür.

Program, Data yapısının adresini serileştirip deserileştirerek orijinal işaretçiyle eşit olup olmadığını kontrol eder. Bu alıştırma, `reinterpret_cast` operatörünün kullanımını göstermektedir.

**Örnek Kullanım:**
```cpp
uintptr_t raw = Serializer::serialize(&data);
Data* ptr = Serializer::deserialize(raw);

std::cout << "c: " << ptr->c << std::endl;
std::cout << "i: " << ptr->i << std::endl;
std::cout << "d: " << ptr->d << std::endl;
std::cout << "b: " << ptr->b << std::endl;
```

### Ex02: Gerçek Tür Tanımlama
Bu alıştırmada, sanal bir yıkıcıya sahip `Base` sınıfı ve bu sınıftan türetilen `A`, `B` ve `C` sınıfları bulunur. Program, şu fonksiyonları içerir:

- `Base* generate(void)`: Rastgele A, B veya C sınıfından bir nesne oluşturur ve Base işaretçisi olarak döndürür.
- `void identify(Base* p)`: Verilen işaretçinin gerçek tipini (A, B veya C) ekrana yazdırır.
- `void identify(Base& p)`: Verilen referansın gerçek tipini (A, B veya C) ekrana yazdırır, ancak bu fonksiyon içinde işaretçi kullanımı yasaktır.

Bu alıştırma, `typeinfo` başlığını kullanmadan çalışma zamanında nesne tiplerinin nasıl belirlenebileceğini göstermektedir. Burada `dynamic_cast` operatörünün kullanımı öğrenilmektedir.

## Önemli Cast Operatörleri

### 1. static_cast vs reinterpret_cast
#### static_cast
- Derleyici tarafından kontrol edilen güvenli dönüşümler için kullanılır
- Derleme zamanında (compile-time) dönüşümü yapar ve hatalı durumları tespit edebilir
- Verinin bellekte nasıl temsil edildiğini değiştirmez, sadece türü değiştirir
- Sayısal türler (int → float, char → int gibi) arasında dönüşüm yapabilir
- Pointer dönüşümlerinde, yalnızca ilişkili sınıflar (Base* → Derived*) arasında çalışır
- Çalışma mantığı: Derleyiciye "bu dönüşüm mantıklı mı?" diye sorar ve mantıklıysa tipi değiştirir

#### reinterpret_cast
- Bir türü tamamen farklı bir türe yorumlamak için kullanılır
- Bellekteki bitleri değiştirmez, sadece farklı bir tür gibi yorumlar
- Derleyici herhangi bir kontrol yapmaz, dönüşümün mantıklı olup olmadığını kontrol etmez
- Farklı pointer türleri arasında dönüşüm yapabilir (int* → double*, void* → int* gibi)
- Düşük seviyeli (low-level) dönüşümler ve sistem bağımlı işlemler için uygundur
- Çalışma mantığı: Bellekteki adresi ham veri olarak alır ve "Bu veriye başka bir tür gibi bak" der

### 2. dynamic_cast ve RTTI (Run-Time Type Information)
#### dynamic_cast Ne İşe Yarar?
- Bir nesnenin gerçek türünü kontrol ederek, tür dönüşümünün güvenliğini sağlar
- Bir taban sınıf işaretçisinin gerçekte hangi türetilmiş sınıfa ait olduğunu belirler
- Yanlış tür dönüşümlerini önler (Base* → Derived* dönüşümünde nesne gerçekten Derived değilse nullptr döner)
- Çoklu kalıtım durumlarında tür uyumluluğunu kontrol eder

#### Çalışma Prensibi
- Çalışma zamanında nesnenin türünü belirlemek için RTTI mekanizmasını kullanır
- Nesnenin sanal fonksiyon tablosuna (vtable) erişerek tür bilgisini alır
- Hedef türle mevcut türün uyumlu olup olmadığını kontrol eder
- Uyumluysa dönüşüm yapar; değilse işaretçiler için nullptr, referanslar için std::bad_cast exception fırlatır

#### Gereklilikler
- Taban sınıfın en az bir sanal (virtual) fonksiyonu olmalıdır
- Virtual fonksiyon olmazsa, derleyici vtable ve RTTI oluşturmaz
- RTTI olmadan dynamic_cast, nesnenin gerçek türünü belirleyemez

## uintptr_t Hakkında Önemli Bilgiler

### Pointer'ları Sayıya Çevirmek: uintptr_t vs int
Bir işaretçiyi sayı türüne dönüştürmek istediğimizde neden int yerine uintptr_t kullanmalıyız:

1. **int Kullanmanın Riski**
   - 64-bit bir bilgisayarda, işaretçiler 64 bit (8 byte) iken int genelde 32 bit (4 byte) boyutundadır
   - int kullanılırsa, işaretçinin üst bitleri kesilir ve veri kaybı olur
   - Örnek: 0x7ffeeb0d1234 (64-bit) → 0xeb0d1234 (32-bit)
   - Bu durum, programın çökmesine veya gizli hatalara neden olabilir

2. **uintptr_t'nin Avantajları**
   - İşaretçinin tüm bitlerini korur (64-bit sistemde 64-bit tam sayı olacaktır)
   - Platformdan bağımsızdır (32-bit veya 64-bit sistem fark etmez)
   - İşaretçi üzerinde aritmetik işlemler yapılabilir
   - Örnek: `uintptr_t adres = reinterpret_cast<uintptr_t>(ptr);` // Tüm adres korunur

## Struct Padding ve Bellek Düzeni

Struct padding, derleyicinin veri hizalama kurallarına uyması için bellek içinde boşluklar (padding bytes) eklemesidir. Bu, işlemcinin veri erişimini hızlandırmak ve bellek erişim hatalarını önlemek amacıyla yapılır.

### Neden Padding Yapılır?
1. **Hizalama (Alignment):**
   - İşlemciler verileri belleğin belirli adreslerinde hizalanmış olarak okumayı tercih eder
   - Örneğin, double genellikle 8 bayt hizalanmış bir adreste saklanmalıdır

2. **Performans Artışı:**
   - Bellek veriye hizalanmış adreslerden eriştiğinde, CPU daha hızlı çalışır
   - Yanlış hizalama, bazı işlemcilerde cezaya (penalty) neden olabilir

3. **Bellek Erişim Hatalarını Önleme:**
   - Bazı işlemciler yanlış hizalanmış bellek erişimine izin vermez ve program çöker

### Padding Örneği
```cpp
struct MyStruct {
    char a;     // 1 byte
    int b;      // 4 byte (4'e hizalanmalı, 3 byte padding eklenir)
    double c;   // 8 byte (8'e hizalanmalı, gerekirse padding eklenir)
};
```

Bellek düzeni:
```
a (1 byte) | padding (3 bytes) | b (4 bytes) | c (8 bytes)
```

Toplam 16 byte olur, ancak aslında 13 byte veri vardır, 3 byte padding eklenmiştir.

### Padding'i Azaltma Teknikleri
Üye sıralamasını değiştirerek padding'i azaltabiliriz:
```cpp
struct Optimized {
    double c;  // 8 byte
    int b;     // 4 byte
    char a;    // 1 byte
    // 3 byte padding
};
```

Bu düzenleme padding miktarını azaltabilir.

## Derleyici ve Standartlar
Bu projede C++98 standardı kullanılmaktadır. Her alıştırma klasöründe, gerekli dosyaları derlemek için bir Makefile bulunmaktadır.

## Kaynaklar
- [C++ Type Conversion](https://www.geeksforgeeks.org/type-conversion-in-c/)
- [Casting Operators in C++](https://www.geeksforgeeks.org/casting-operators-in-cpp/)
- [reinterpret_cast in C++](https://www.geeksforgeeks.org/reinterpret_cast-in-c-type-casting-operators/)
- [reinterpret_cast Video Anlatımı](https://www.youtube.com/watch?v=JBvEfB_F66o)