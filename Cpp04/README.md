# C++ Module 04

## Polymorphism, Soyut Sınıflar ve Arayüzler

Bu modül, C++'ta polymorphism, soyut sınıflar ve arayüzler konularını anlamaya yardımcı olmak amacıyla hazırlanmıştır. Konular, örnek uygulamalarla desteklenerek anlatılmaktadır.

## İçerik

1. [Exercise 00: Polymorphism](#exercise-00-polymorphism)
2. [Exercise 01: Deep Copy ve Kaynak Yönetimi](#exercise-01-deep-copy-ve-kaynak-yonetimi)
3. [Exercise 02: Abstract Classes](#exercise-02-abstract-classes)
4. [Exercise 03: Interface Kullanımı ve Özet](#exercise-03-interface-kullanimi-ve-ozet)

## Önemli Konular

### Exercise 00: Polymorphism

Bu bölümde, polymorphism kavramı hayvan sınıflarını temel alan bir hiyerarşi ile incelenmektedir.

#### Uygulanması Gerekenler

- `Animal` adında bir temel sınıf tanımlanmalıdır. Bu sınıfın aşağıdaki korumalı üye değişkeni bulunmalıdır:
  ```cpp
  std::string type;
  ```
- `Animal` sınıfından türetilen `Dog` ve `Cat` sınıfları oluşturulmalıdır.
- Her sınıf, `type` değişkenini uygun şekilde ayarlamalıdır.
- `makeSound()` üye fonksiyonu, ilgili hayvanın çıkardığı sesi ekrana yazdırmalıdır.
- Polymorphism kavramını daha iyi anlamak için `WrongAnimal` ve `WrongCat` sınıfları oluşturulmalıdır.

### Exercise 01: Deep Copy ve Kaynak Yönetimi

Bu bölümde, polymorphism ile birlikte deep copy ve dinamik bellek yönetimi ele alınmaktadır.

#### Uygulanması Gerekenler

- `Brain` adında bir sınıf oluşturulmalıdır:
  - `std::string` türünde 100 elemanlı bir `ideas` dizisi içermelidir.
- `Dog` ve `Cat` sınıflarına özel bir `Brain*` işaretçisi eklenmelidir.
- `main()` fonksiyonunda `Animal` nesnelerinden oluşan bir dizi tanımlanmalıdır.
- `Dog` ve `Cat` sınıflarında kopyalama işlemi yüzeysel olmamalı, deep copy uygulanmalıdır.

### Exercise 02: Abstract Classes

Bu bölümde, soyut sınıfların kullanımı ve saf sanal fonksiyonlar ele alınmaktadır.

#### Uygulanması Gerekenler

- `Animal` sınıfı soyut hale getirilmeli ve doğrudan örneklenmesi engellenmelidir.
- Sınıf ismi `Animal` yerine `AAnimal` olarak değiştirilebilir.

![Virtual Table](https://github.com/menasy/Project_icons/blob/main/Cpp_ModuleImages/VirtualTable.png)

### Exercise 03: Interface Kullanımı ve Özet

Bu bölümde, C++'ta interface'lerin nasıl oluşturulacağı ve kullanılacağı ele alınmaktadır.

#### Uygulanması Gerekenler

- `AMateria` sınıfı tamamlanmalı ve gerekli üye fonksiyonları uygulanmalıdır.
- `Ice` ve `Cure` gibi `AMateria` sınıfından türeyen somut sınıflar oluşturulmalıdır.
- `Character` sınıfı aşağıdaki arayüzü kullanarak uygulanmalıdır:
  ```cpp
  class ICharacter {
  public:
      virtual ~ICharacter() {}
      virtual std::string const & getName() const = 0;
      virtual void equip(AMateria* m) = 0;
      virtual void unequip(int idx) = 0;
      virtual void use(int idx, ICharacter& target) = 0;
  };
  ```
- `MateriaSource` sınıfı aşağıdaki arayüzü kullanarak uygulanmalıdır:
  ```cpp
  class IMateriaSource {
  public:
      virtual ~IMateriaSource() {}
      virtual void learnMateria(AMateria*) = 0;
      virtual AMateria* createMateria(std::string const & type) = 0;
  };
  ```

![Virtual Table 2](https://github.com/menasy/Project_icons/blob/main/Cpp_ModuleImages/VirtualTable2.png)

## Özet

### Polymorphism

- **Derleme Zamanı Polymorphism (Statik):** Fonksiyon aşırı yükleme ve operatör aşırı yükleme ile gerçekleştirilir.
- **Çalışma Zamanı Polymorphism (Dinamik):** Sanal fonksiyonlar aracılığıyla sağlanır.

### Stack ve Heap’te Polymorphism

- **Stack Tanımlaması:** `Animal b = a;` → Statik bağlama.
- **Heap Tanımlaması:** `Animal *b = a;` veya `Animal &b = a;` → Dinamik bağlama.

### Virtual Table

- Virtual Table, çalışma zamanında hangi üye fonksiyonun çağrılacağını belirlemek için kullanılır.
- Sanal fonksiyon içeren sınıflar için derleyici tarafından otomatik olarak oluşturulur.

### Abstract Classes ve Saf Sanal Fonksiyonlar

- Saf sanal fonksiyonlar `= 0` ile tanımlanır:
  ```cpp
  virtual void makeSound() = 0;
  ```
- Abstract classes doğrudan örneklenemez.

### Interface

- Tüm üye fonksiyonları saf sanal fonksiyon (`= 0`) olmalıdır.
- Veri üyeleri olmamalıdır, yalnızca davranışı tanımlar.
- Interface'i uygulayan sınıf, tüm saf sanal fonksiyonları tanımlamalıdır.

## Kaynaklar

- **Polymorphism:** [GeeksforGeeks - C++ Polymorphism](https://www.geeksforgeeks.org/cpp-polymorphism/)
- **Virtual Destructor:** [JavaTpoint - Virtual Destructor](https://www.javatpoint.com/virtual-destructor-in-cpp)
- **Virtual Table:** [LearnCPP - The Virtual Table](https://www.learncpp.com/cpp-tutorial/the-virtual-table/)
- **Abstract Classes:** [LearnCPP - Abstract Classes](https://www.learncpp.com/cpp-tutorial/pure-virtual-functions-abstract-base-classes-and-interface-classes/)
