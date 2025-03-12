# C++ Module 04

## Polymorphism, Abstract Class ve Interface

Bu modül, C++'da Polymorphism, Abstract Class ve Interface kavramlarını anlamanızı sağlamak için tasarlanmıştır. Modül içerisinde bu kavramları pratik uygulamalarla öğreneceksiniz.

## İçerik

- **Exercise 00: Polymorphism**
- **Exercise 01: Dünyayı Ateşe Vermek İstemiyorum**
- **Exercise 02: Abstract Class**
- **Exercise 03: Interface & Summary**

## Önemli Kavramlar

### Exercise 00: Polymorphism

Bu alıştırmada, Polymorphism kavramını basit bir hayvan sınıfı hiyerarşisi üzerinden öğreneceksiniz.

### Gereksinimler

- `Animal` adında bir temel sınıf oluşturun. Bu sınıfın korumalı bir özniteliği olmalı:
  ```cpp
  std::string type;
  ```
- `Animal` sınıfından türetilen `Dog` ve `Cat` sınıfları oluşturun.
- Her sınıf kendi türüne göre `type` değişkenini ayarlamalı.
- `makeSound()` üye fonksiyonu uygun sesi yazdırmalı (kediler havlamaz).
- Polymorphism konseptini daha iyi anlamak için `WrongAnimal` ve `WrongCat` sınıfları da oluşturmalısınız.

![Virtual Table](https://github.com/menasy/Project_icons/blob/main/Cpp_ModuleImages/VirtualTable.png)

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

Bu alıştırmada, Polymorphism ve derin kopyalama kavramlarını pekiştireceğiz.

### Gereksinimler

- `Brain` adında bir sınıf oluşturun:
  - `100` adet `std::string` içeren `ideas` adında bir dizi içermeli.
- `Dog` ve `Cat` sınıflarını özel bir `Brain` işaretçisine sahip olacak şekilde güncelleyin.
- `main()` fonksiyonunda `Animal` nesnelerinden oluşan bir dizi oluşturun.
- `Dog` veya `Cat` kopyaları yüzeysel olmamalı, derin kopyalama gerçekleştirilmeli.

---

### Exercise 02: Abstract Class

Bu alıştırmada, Abstract Class kavramını öğreneceksiniz.

### Gereksinimler

- `Animal` sınıfını kimse somutlaştıramayacak şekilde düzeltin.
- İsterseniz, sınıf adını `Animal`'dan `AAnimal`'a güncelleyebilirsiniz.

### Kaynaklar

- **Abstract Classes:**
  - [LearnCPP - Pure Virtual Functions & Abstract Base Classes](https://www.learncpp.com/cpp-tutorial/pure-virtual-functions-abstract-base-classes-and-interface-classes/)

---

### Exercise 03: Interface & Summary

Bu alıştırmada, C++'da Interface kavramını (saf soyut sınıflar) uygulamaya çalışacağız.

### Gereksinimler

- `AMateria` sınıfını tamamlayın ve gerekli üye fonksiyonları uygulayın.
- `Ice` ve `Cure` gibi somut `AMateria` sınıflarını oluşturun.
- `Character` sınıfını aşağıdaki Interface'i uygulayarak yazın:
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
- `MateriaSource` sınıfını aşağıdaki Interface'i uygulayarak yazın:
  ```cpp
  class IMateriaSource {
  public:
      virtual ~IMateriaSource() {}
      virtual void learnMateria(AMateria*) = 0;
      virtual AMateria* createMateria(std::string const & type) = 0;
  };
  ```

![Virtual Table 2](https://github.com/menasy/Project_icons/blob/main/Cpp_ModuleImages/VirtualTable2.png)

## Önemli Kavramlar

### Polymorphism

- **Derleme Zamanı Polymorphism (Statik):** Fonksiyon aşırı yükleme ve operatör aşırı yükleme.
- **Çalışma Zamanı Polymorphism (Dinamik):** Sanal fonksiyonlar kullanılarak elde edilir.

### Stack ve Heap'te Polymorphism

- **Stack'te Tanımlama:** `Animal b = a;` → Statik bağlama.
- **Heap'te Tanımlama:** `Animal *b = a;` veya `Animal &b = a;` → Dinamik bağlama.

### Virtual Table

- Virtual Table, çalışma zamanında hangi üye fonksiyonun çağrılacağını belirlemek için kullanılan bir veri yapısıdır.
- Derleyici, sanal fonksiyon içeren sınıflar için bir Virtual Table oluşturur.

### Abstract Class ve Saf Sanal Fonksiyonlar

- Saf sanal fonksiyonlar `= 0` ile tanımlanır:
  ```cpp
  virtual void makeSound() = 0;
  ```
- Bir Abstract Class doğrudan örneklenemez.

### Interface

- Tüm üye fonksiyonları saf sanal olmalıdır (`= 0`).
- Veri üyeleri olmamalıdır (sadece davranışı tanımlar).
- Uygulayan sınıf, tüm saf sanal fonksiyonları uygulamalıdır.

## Kaynaklar

- **Polymorphism:** [GeeksforGeeks - C++ Polymorphism](https://www.geeksforgeeks.org/cpp-polymorphism/)
- **Virtual Destructor:** [JavaTpoint - Virtual Destructor](https://www.javatpoint.com/virtual-destructor-in-cpp)
- **Virtual Table:** [LearnCPP - The Virtual Table](https://www.learncpp.com/cpp-tutorial/the-virtual-table/)
- **Abstract Class:** [LearnCPP - Abstract Classes](https://www.learncpp.com/cpp-tutorial/pure-virtual-functions-abstract-base-classes-and-interface-classes/)
# C++ Module 04

## Polymorphism, Abstract Class ve Interface

Bu modül, C++'da Polymorphism, Abstract Class ve Interface kavramlarını anlamanızı sağlamak için tasarlanmıştır. Modül içerisinde bu kavramları pratik uygulamalarla öğreneceksiniz.

## İçerik

- **Exercise 00: Polymorphism**
- **Exercise 01: Dünyayı Ateşe Vermek İstemiyorum**
- **Exercise 02: Abstract Class**
- **Exercise 03: Interface & Summary**

## Önemli Kavramlar

### Exercise 00: Polymorphism

Bu alıştırmada, Polymorphism kavramını basit bir hayvan sınıfı hiyerarşisi üzerinden öğreneceksiniz.

### Gereksinimler

- `Animal` adında bir temel sınıf oluşturun. Bu sınıfın korumalı bir özniteliği olmalı:
  ```cpp
  std::string type;
  ```
- `Animal` sınıfından türetilen `Dog` ve `Cat` sınıfları oluşturun.
- Her sınıf kendi türüne göre `type` değişkenini ayarlamalı.
- `makeSound()` üye fonksiyonu uygun sesi yazdırmalı (kediler havlamaz).
- Polymorphism konseptini daha iyi anlamak için `WrongAnimal` ve `WrongCat` sınıfları da oluşturmalısınız.

![Virtual Table](https://github.com/menasy/Project_icons/blob/main/Cpp_ModuleImages/VirtualTable.png)

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

Bu alıştırmada, Polymorphism ve derin kopyalama kavramlarını pekiştireceğiz.

### Gereksinimler

- `Brain` adında bir sınıf oluşturun:
  - `100` adet `std::string` içeren `ideas` adında bir dizi içermeli.
- `Dog` ve `Cat` sınıflarını özel bir `Brain` işaretçisine sahip olacak şekilde güncelleyin.
- `main()` fonksiyonunda `Animal` nesnelerinden oluşan bir dizi oluşturun.
- `Dog` veya `Cat` kopyaları yüzeysel olmamalı, derin kopyalama gerçekleştirilmeli.

---

### Exercise 02: Abstract Class

Bu alıştırmada, Abstract Class kavramını öğreneceksiniz.

### Gereksinimler

- `Animal` sınıfını kimse somutlaştıramayacak şekilde düzeltin.
- İsterseniz, sınıf adını `Animal`'dan `AAnimal`'a güncelleyebilirsiniz.

### Kaynaklar

- **Abstract Classes:**
  - [LearnCPP - Pure Virtual Functions & Abstract Base Classes](https://www.learncpp.com/cpp-tutorial/pure-virtual-functions-abstract-base-classes-and-interface-classes/)

---

### Exercise 03: Interface & Summary

Bu alıştırmada, C++'da Interface kavramını (saf soyut sınıflar) uygulamaya çalışacağız.

### Gereksinimler

- `AMateria` sınıfını tamamlayın ve gerekli üye fonksiyonları uygulayın.
- `Ice` ve `Cure` gibi somut `AMateria` sınıflarını oluşturun.
- `Character` sınıfını aşağıdaki Interface'i uygulayarak yazın:
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
- `MateriaSource` sınıfını aşağıdaki Interface'i uygulayarak yazın:
  ```cpp
  class IMateriaSource {
  public:
      virtual ~IMateriaSource() {}
      virtual void learnMateria(AMateria*) = 0;
      virtual AMateria* createMateria(std::string const & type) = 0;
  };
  ```

![Virtual Table 2](https://github.com/menasy/Project_icons/blob/main/Cpp_ModuleImages/VirtualTable2.png)

## Önemli Kavramlar

### Polymorphism

- **Derleme Zamanı Polymorphism (Statik):** Fonksiyon aşırı yükleme ve operatör aşırı yükleme.
- **Çalışma Zamanı Polymorphism (Dinamik):** Sanal fonksiyonlar kullanılarak elde edilir.

### Stack ve Heap'te Polymorphism

- **Stack'te Tanımlama:** `Animal b = a;` → Statik bağlama.
- **Heap'te Tanımlama:** `Animal *b = a;` veya `Animal &b = a;` → Dinamik bağlama.

### Virtual Table

- Virtual Table, çalışma zamanında hangi üye fonksiyonun çağrılacağını belirlemek için kullanılan bir veri yapısıdır.
- Derleyici, sanal fonksiyon içeren sınıflar için bir Virtual Table oluşturur.

### Abstract Class ve Saf Sanal Fonksiyonlar

- Saf sanal fonksiyonlar `= 0` ile tanımlanır:
  ```cpp
  virtual void makeSound() = 0;
  ```
- Bir Abstract Class doğrudan örneklenemez.

### Interface

- Tüm üye fonksiyonları saf sanal olmalıdır (`= 0`).
- Veri üyeleri olmamalıdır (sadece davranışı tanımlar).
- Uygulayan sınıf, tüm saf sanal fonksiyonları uygulamalıdır.

## Kaynaklar

- **Polymorphism:** [GeeksforGeeks - C++ Polymorphism](https://www.geeksforgeeks.org/cpp-polymorphism/)
- **Virtual Destructor:** [JavaTpoint - Virtual Destructor](https://www.javatpoint.com/virtual-destructor-in-cpp)
- **Virtual Table:** [LearnCPP - The Virtual Table](https://www.learncpp.com/cpp-tutorial/the-virtual-table/)
- **Abstract Class:** [LearnCPP - Abstract Classes](https://www.learncpp.com/cpp-tutorial/pure-virtual-functions-abstract-base-classes-and-interface-classes/)
