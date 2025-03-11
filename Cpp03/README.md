# C++ Module 03

## Kalıtım (Inheritance)

Bu modül, C++'da kalıtım (inheritance) kavramını anlamanıza yardımcı olmak için tasarlanmıştır. Modül kapsamında Borderlands oyunundan esinlenilen karakterler kullanarak kalıtım mekanizmalarını uygulamaya çalışacağız.

![Inheritance Access Types](https://github.com/menasy/Project_icons/blob/main/Cpp_ModuleImages/InheritanceAccess.png)

## İçerik

- [Exercise 00: Aaaaand... OPEN!](#exercise-00-aaaaand-open)
- [Exercise 01: Serena, my love!](#exercise-01-serena-my-love)
- [Exercise 02: Repetitive work](#exercise-02-repetitive-work)
- [Exercise 03: Now it's weird!](#exercise-03-now-its-weird)
- [Önemli Kavramlar](#önemli-kavramlar)
- [Kaynaklar](#kaynaklar)

## Exercise 00: Aaaaand... OPEN!

Bu alıştırmada, ClapTrap adlı bir sınıf oluşturmanız gerekiyor.

### Gereksinimler

- **Özel (Private) Üyeler:**
  - İsim (constructor parametresi olarak alınır)
  - Hit points (10), ClapTrap'in sağlık durumunu temsil eder
  - Energy points (10)
  - Attack damage (0)

- **Genel (Public) Üyeler:**
  - `void attack(const std::string& target);` - Hedef, <attack damage> kadar hit point kaybeder
  - `void takeDamage(unsigned int amount);` - ClapTrap belirtilen miktar kadar hasar alır
  - `void beRepaired(unsigned int amount);` - ClapTrap belirtilen miktar kadar iyileşir

Saldırı ve tamir işlemleri 1 enerji puanına mal olur. ClapTrap'in hit point'i veya enerji puanı kalmadığında hiçbir şey yapamaz.

## Exercise 01: Serena, my love!

Bu alıştırmada, ClapTrap'ten türetilen ScavTrap adlı bir sınıf oluşturmanız gerekiyor.

### Gereksinimler

- ScavTrap, ClapTrap'ten miras alır ve constructorlar ile destructor'ı ClapTrap'ten devralır
- ScavTrap'in constructor, destructor ve attack() fonksiyonları farklı mesajlar yazdırmalıdır
- Constructor/destructor zincirlemesi testlerde gösterilmelidir

- **Özellikler:**
  - İsim (constructor parametresi olarak alınır)
  - Hit points (100)
  - Energy points (50)
  - Attack damage (20)

- **Özel Yetenek:**
  - `void guardGate();` - ScavTrap'in "Gate keeper" moduna geçtiğini belirten bir mesaj görüntüler

## Exercise 02: Repetitive work

Bu alıştırmada, ClapTrap'ten türetilen FragTrap adlı bir sınıf oluşturmanız gerekiyor.

### Gereksinimler

- FragTrap, ClapTrap'ten miras alır
- Constructor ve destructor mesajları ScavTrap'ten farklı olmalıdır
- Constructor/destructor zincirlemesi testlerde gösterilmelidir

- **Özellikler:**
  - İsim (constructor parametresi olarak alınır)
  - Hit points (100)
  - Energy points (100)
  - Attack damage (30)

- **Özel Yetenek:**
  - `void highFivesGuys(void);` - Standart çıktıda olumlu bir high five isteği görüntüler

## Exercise 03: Now it's weird!

Bu alıştırmada, hem FragTrap hem de ScavTrap'ten türetilen DiamondTrap adlı bir sınıf oluşturmanız gerekiyor (çoklu kalıtım).

### Gereksinimler

- DiamondTrap, hem FragTrap hem de ScavTrap'ten miras alır
- DiamondTrap sınıfının, ClapTrap temel sınıfındakiyle aynı isimde bir private isim değişkeni olacaktır

- **Özellikler:**
  - İsim (constructor parametresi olarak alınır)
  - ClapTrap::name (parametre + "_clap_name" son eki)
  - Hit points (FragTrap'ten)
  - Energy points (ScavTrap'ten)
  - Attack damage (FragTrap'ten)
  - attack() (ScavTrap'ten)

- **Özel Yetenek:**
  - `void whoAmI();` - Hem kendi adını hem de ClapTrap adını görüntüler

ClapTrap alt nesnesi, DiamondTrap için yalnızca bir kez oluşturulmalıdır (Elmas problemi).

## Önemli Kavramlar

### Kalıtım (Inheritance)

Kalıtım, bir sınıfın özelliklerini başka bir sınıfa aktarma mekanizmasıdır. Bu, kod tekrarını azaltır ve hiyerarşik sınıf yapıları oluşturmayı sağlar.

### Temel Kalıtım Türleri

1. **Tekli Kalıtım (Single Inheritance)**:
   - Bir sınıf yalnızca bir sınıftan türetilir
   - `class Derived : public Base { };`

2. **Çoklu Kalıtım (Multiple Inheritance)**:
   - Bir sınıf birden fazla sınıftan türetilir
   - `class Derived : public Base1, public Base2 { };`

3. **Çok Seviyeli Kalıtım (Multilevel Inheritance)**:
   - Türetilmiş bir sınıf başka bir türetilmiş sınıfın temel sınıfı olur
   - `class C : public B { };` (B daha önce A'dan türetilmişse)

### Constructor ve Destructor Davranışı

1. **Constructor Çalışma Sırası**:
   - Temel sınıfın constructor'ı önce çalışır, ardından türetilmiş sınıfın constructor'ı çalışır
   - Bir nesne oluşturulduğunda, miras hiyerarşisinde yukarıdan aşağıya doğru constructor'lar çağrılır

2. **Destructor Çalışma Sırası**:
   - Türetilmiş sınıfın destructor'ı önce çalışır, ardından temel sınıfın destructor'ı çalışır
   - Bir nesne imha edildiğinde, miras hiyerarşisinde aşağıdan yukarıya doğru destructor'lar çağrılır
   - Bu sıralama, bellek sızıntılarını ve diğer kaynakların düzgün şekilde serbest bırakılmamasını önlemek için önemlidir

### Atama Operatörü ve Kalıtım

1. **Upcasting (Yukarı Dönüşüm)**:
   - Türetilmiş sınıf nesnesi temel sınıf nesnesine atanabilir (ScavTrap -> ClapTrap)
   - Bu durumda sadece temel sınıf kısmı kopyalanır, türetilmiş sınıfa özgü üyeler dikkate alınmaz

2. **Downcasting (Aşağı Dönüşüm)**:
   - Temel sınıf nesnesi doğrudan türetilmiş sınıf nesnesine atanamaz (ClapTrap -> ScavTrap)
   - Derleyici, temel sınıf türünden türetilmiş sınıf türüne doğrudan atama işlemini desteklemez
   - Türetilmiş sınıfa özgü kısımlar eksik olacağı için bu atama güvenli değildir

### Elmas Problemi ve Sanal Kalıtım (Diamond Problem and Virtual Inheritance)

1. **Elmas Problemi**:
   ```
   class A { /* ... */ };
   class B : public A { /* ... */ };
   class C : public A { /* ... */ };
   class D : public B, public C { /* ... */ };
   ```
   - D sınıfı, A sınıfının iki kopyasını içerir: biri B üzerinden, diğeri C üzerinden
   - A'da tanımlanan bir üyeye erişildiğinde, hangi kopyanın kullanılacağı belirsizdir

2. **Sanal Kalıtım**:
   ```
   class B : virtual public A { /* ... */ };
   class C : virtual public A { /* ... */ };
   class D : public B, public C { /* ... */ };
   ```
   - `virtual` anahtar kelimesi ile, A sınıfının yalnızca bir kopyası oluşturulur
   - Sanal kalıtım, elmas problemini çözer
   - D sınıfı A'nın bir örneğini oluşturur ve B ile C bu örneğe referans tutarlar

## Kaynaklar

### Genel
- [C++ Inheritance](https://www.javatpoint.com/cpp-inheritance)
- [Order of Constructor and Destructor Call in C++](https://www.geeksforgeeks.org/order-constructor-destructor-call-c/)
- [Multiple Inheritance in C++](https://www.geeksforgeeks.org/multiple-inheritance-in-c/)

### Oyun Karakterleri Hakkında
- ClapTrap, ScavTrap ve FragTrap, Borderlands adlı video oyunundan esinlenilen hayali robot karakterlerdir
- Bu karakterler, programlama eğitimlerinde kalıtım ve çok biçimlilik konularını öğretmek için ideal örneklerdir