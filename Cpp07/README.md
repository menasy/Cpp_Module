# C++ Module 07 - C++ Şablonlar (Templates)

Bu modül, C++ programlama dilindeki şablonları (templates) incelemeye odaklanmaktadır. Şablonlar, farklı veri tipleriyle çalışabilen genel kod yazmanızı sağlar.

## İçindekiler

1. Exercise 00: Start with a few functions
2. Exercise 01: Iter
3. Exercise 02: Array

## Şablonlar Hakkında Önemli Notlar

### Şablonlar Neden Header Dosyasında Olmalı?

C++'da şablonlar derleme zamanında (compile-time) işlenir. Ancak şablonların hangi türler (T) ile kullanılacağını derleyici önceden bilemez.

C++'da normal fonksiyonlar veya sınıflar `.cpp` dosyalarında tanımlanıp `.h` dosyalarında bildirilebilir. Ancak şablonlar farklıdır, çünkü şablonların türü belirlenmeden (T ne olacak bilinmeden) derlenmesi mümkün değildir.

Derleyici, bir şablonun hangi türlerle kullanılacağını ancak şablonun kullanıldığı yerde öğrenebilir. İşte bu yüzden şablon tanımları genellikle `.h` veya `.hpp` dosyasında yazılır.

### Şablonları .cpp Dosyasında Kullanırsan Ne Olur?

Eğer bir şablon fonksiyonu veya sınıfı `.cpp` dosyasında tanımlarsan, derleyici şablonu önceden göremediği türlerle derleyemez ve "undefined reference" hatası alırsın.

### Fonksiyon Şablonları ve Statik Değişkenler

Bir fonksiyon şablonu (function template), çağrıldığı türlere göre farklı örnekler (instances) oluşturur. Eğer fonksiyonun içinde bir statik değişken varsa, her türe özgü bir ayrı kopyası oluşur.

Bir fonksiyon içinde static bir değişken tanımlandığında, bu değişken yalnızca bir defa oluşturulur ve fonksiyon çağrıları arasında değerini korur.

Fakat fonksiyon şablonları, her farklı tür için ayrı bir fonksiyon oluşturduğu için, her tür için ayrı bir statik değişken kopyası olur.

Örnek olarak:

```cpp
template <typename T>
void fun(T x) {
    static int i = 0; // Her türe özel ayrı bir statik değişken
    i++;  
    std::cout << "Türe özel i: " << i << std::endl;
}

int main() {
    fun(10);    // fun<int> çağrılır (i = 1)
    fun(20);    // fun<int> çağrılır (i = 2)
    fun(30);    // fun<int> çağrılır (i = 3)
    fun(3.14);  // fun<double> çağrılır (yeni i = 1)
    fun(6.28);  // fun<double> çağrılır (yeni i = 2)
    fun(10);    // fun<int> çağrılır (i = 4)
    return 0;
}
```

## Exercise 00: Start with a few functions

Bu alıştırmada, üç temel şablon fonksiyonu uygulanır:

- `swap`: İki değişkenin değerlerini değiştirir. Hiçbir şey döndürmez.
- `min`: İki değer arasından küçük olanı döndürür. Eşitlik durumunda ikinci değeri döndürür.
- `max`: İki değer arasından büyük olanı döndürür. Eşitlik durumunda ikinci değeri döndürür.

Bu fonksiyonlar herhangi bir tipte argümanla çağrılabilir. Tek gereksinim, iki argümanın aynı tipte olması ve tüm karşılaştırma operatörlerini desteklemesidir.

Şablonlar header dosyalarında tanımlanmalıdır.

## Exercise 01: Iter

Bu alıştırmada, şu üç parametreyi alan bir `iter` şablon fonksiyonu uygulanır:

- Bir dizinin adresi
- Dizinin uzunluğu
- Dizinin her elemanı için çağrılacak bir fonksiyon

Fonksiyon şablonu, herhangi bir tipteki dizi ile çalışabilmelidir. Üçüncü parametre, bir şablon fonksiyonu örneği olabilir.

## Exercise 02: Array

Bu alıştırmada, T tipinde elemanlar içeren bir `Array` sınıf şablonu geliştirilir. Bu sınıf şu davranışları ve fonksiyonları içerir:

- Parametresiz yapıcı: Boş bir dizi oluşturur.
- Unsigned int n parametreli yapıcı: Varsayılan olarak başlatılmış n elemanlı bir dizi oluşturur.
  - İpucu: `int * a = new int();` derleyip `*a`'yı görüntüleyin.
- Kopyalama yapıcısı ve atama operatörü. Her iki durumda da, kopyalamadan sonra orijinal diziyi veya kopyasını değiştirmek diğer diziyi etkilememelidir.
- Bellek ayırmak için `new[]` operatörü KULLANILMALIDIR. Koruyucu tahsis (belleği önceden ayırmak) yasaktır. Programınız asla tahsis edilmemiş belleğe erişmemelidir.
- Elemanlara `[]` operatörü ile erişilebilir.
- `[]` operatörü ile erişilirken, indeks sınırların dışındaysa, bir `std::exception` atılır.
- Dizideki eleman sayısını döndüren bir `size()` üye fonksiyonu. Bu üye fonksiyon hiçbir parametre almaz ve mevcut örneği değiştirmemelidir.

## Kaynaklar

- [GeeksforGeeks: Templates in C++](https://www.geeksforgeeks.org/templates-cpp/)