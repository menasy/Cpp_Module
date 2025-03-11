# C++ Module 04

## Polimorfizm, Soyut Sınıflar ve Arayüzler

Bu modül, C++'da polimorfizm, soyut sınıflar ve arayüzler kavramlarını anlamanızı sağlamak için tasarlanmıştır. Modül içerisinde bu kavramları pratik uygulamalarla öğreneceksiniz.

## İçerik

- **Exercise 00: Polimorfizm (Polymorphism)**
- **Exercise 01: Dünyayı Ateşe Vermek İstemiyorum**
- **Exercise 02: Soyut Sınıf (Abstract Class)**
- **Exercise 03: Arayüz ve Özet (Interface & Summary)**

## Önemli Kavramlar

### Exercise 00: Polimorfizm

Bu alıştırmada, polimorfizm kavramını basit bir hayvan sınıfı hiyerarşisi üzerinden öğreneceksiniz.

### Gereksinimler

- `Animal` adında bir temel sınıf oluşturun. Bu sınıfın korumalı bir özniteliği olmalı:
  ```cpp
  std::string type;
  ```
- `Animal` sınıfından türetilen `Dog` ve `Cat` sınıfları oluşturun.
- Her sınıf kendi türüne göre `type` değişkenini ayarlamalı.
- `makeSound()` üye fonksiyonu uygun sesi yazdırmalı (kediler havlamaz).
- Polimorfizm konseptini daha iyi anlamak için `WrongAnimal` ve `WrongCat` sınıfları da oluşturmalısınız.

### Kaynaklar

- **Polymorphism:**
  - [GeeksforGeeks - C++ Polymorphism](https://www.geeksforgeeks.org/cpp-polymorphism/)
  - [GeeksforGeeks - Virtual Functions and Runtime Polymorphism](https://www.geeksforgeeks.org/virtual-functions-and-runtime-polymorphism-in-cpp/)
  - [YouTube - Polymorphism Explained](https://www.youtube.com/watch?v=YxN4R-Jie2U)
- **Virtual Destructor:**
  - [JavaTpoint - Virtual Destructor](https://www.javatpoint.com/virtual-destructor-in-cpp)
- **Virtual Table:**
  - [LearnCPP - The Virtual Table](https://www.learncpp.com/cpp-tutorial/the-virtual-table/)

---

### Exercise 01: Dünyayı Ateşe Vermek İstemiyorum

Bu alıştırmada, polimorfizm ve derin kopyalama kavramlarını pekiştireceğiz.

### Gereksinimler

- `Brain` adında bir sınıf oluşturun:
  - `100` adet `std::string` içeren `ideas` adında bir dizi içermeli.
- `Dog` ve `Cat` sınıflarını özel bir `Brain` işaretçisine sahip olacak şekilde güncelleyin.
- `main()` fonksiyonunda `Animal` nesnelerinden oluşan bir dizi oluşturun.
- `Dog` veya `Cat` kopyaları yüzeysel olmamalı, derin kopyalama gerçekleştirilmeli.

---

### Exercise 02: Soyut Sınıf

Bu alıştırmada, soyut sınıf kavramını öğreneceksiniz.

### Gereksinimler

- `Animal` sınıfını kimse somutlaştıramayacak şekilde düzeltin.
- İsterseniz, sınıf adını `Animal`'dan `AAnimal`'a güncelleyebilirsiniz.

### Kaynaklar

- **Abstract Classes:**
  - [LearnCPP - Pure Virtual Functions & Abstract Base Classes](https://www.learncpp.com/cpp-tutorial/pure-virtual-functions-abstract-base-classes-and-interface-classes/)

---

### Exercise 03: Arayüz ve Özet

Bu alıştırmada, C++'da arayüz kavramını (saf soyut sınıflar) uygulamaya çalışacağız.

### Gereksinimler

- `AMateria` sınıfını tamamlayın ve gerekli üye fonksiyonları uygulayın.
- `Ice` ve `Cure` gibi somut `AMateria` sınıflarını oluşturun.
- `Character` sınıfını aşağıdaki arayüzü uygulayarak yazın:
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
- `MateriaSource` sınıfını aşağıdaki arayüzü uygulayarak yazın:
  ```cpp
  class IMateriaSource {
  public:
      virtual ~IMateriaSource() {}
      virtual void learnMateria(AMateria*) = 0;
      virtual AMateria* createMateria(std::string const & type) = 0;
  };
  ```

## Önemli Kavramlar

### Polimorfizm

- **Derleme Zamanı Polimorfizmi (Statik):** Fonksiyon aşırı yükleme ve operatör aşırı yükleme.
- **Çalışma Zamanı Polimorfizmi (Dinamik):** Sanal fonksiyonlar kullanılarak elde edilir.

### Stack ve Heap'te Polimorfizm

- **Stack'te Tanımlama:** `Animal b = a;` → Statik bağlama.
- **Heap'te Tanımlama:** `Animal *b = a;` veya `Animal &b = a;` → Dinamik bağlama.

### Sanal Tablo (Virtual Table)

- Sanal tablo, çalışma zamanında hangi üye fonksiyonun çağrılacağını belirlemek için kullanılan bir veri yapısıdır.
- Derleyici, sanal fonksiyon içeren sınıflar için bir sanal tablo oluşturur.

### Soyut Sınıflar ve Saf Sanal Fonksiyonlar

- Saf sanal fonksiyonlar `= 0` ile tanımlanır:
  ```cpp
  virtual void makeSound() = 0;
  ```
- Bir soyut sınıf doğrudan örneklenemez.

### Arayüzler (Interfaces)

- Tüm üye fonksiyonları saf sanal olmalıdır (`= 0`).
- Veri üyeleri olmamalıdır (sadece davranışı tanımlar).
- Uygulayan sınıf, tüm saf sanal fonksiyonları uygulamalıdır.

## Kaynaklar

**Genel Kaynaklar**

- **Polimorfizm:** [GeeksforGeeks - C++ Polymorphism](https://www.geeksforgeeks.org/cpp-polymorphism/)
- **Sanal Yıkıcı:** [JavaTpoint - Virtual Destructor](https://www.javatpoint.com/virtual-destructor-in-cpp)
- **Sanal Tablo:** [LearnCPP - The Virtual Table](https://www.learncpp.com/cpp-tutorial/the-virtual-table/)
- **Soyut Sınıflar:** [LearnCPP - Abstract Classes](https://www.learncpp.com/cpp-tutorial/pure-virtual-functions-abstract-base-classes-and-interface-classes/)

