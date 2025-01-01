# **C++ Modül Projeleri**

Bu repository, 42 okulu kapsamında tamamladığım C++ modüllerini içermektedir. Her bir modül, C++ dilinin farklı yönlerine odaklanmaktadır ve nesne yönelimli programlama (OOP), bellek yönetimi, polimorfizm, kalıtım ve soyut sınıflar gibi konuları kapsamaktadır.

---

## **Modüller ve Öğrendiklerim**

### [**Cpp00: C++ Temelleri, Sınıflar ve Basit Dosya Yapıları**](https://github.com/menasy/CPP_Module/tree/main/Cpp00)
- **Öğrenilenler:**
  - Getter ve setter kullanarak verilerin dış müdahalelerden korunması (kapsülleme).
  - Sınıf ve nesne yapıları, constructor ve destructor kullanımı.
  - Statik ve statik olmayan değişkenlerin farkları.
  - `iostream` kullanımı ile temel dosya giriş/çıkış işlemleri.

- **Notlar:**
  - **Encapsulation:** Private değerlere getter ve setter ile erişim sağlanarak dışarıdan müdahalelere karşı korunur. Örneğin, yaş değerinin -4 yapılmasını engellemek için kapsülleme kullanılır.
  - **Delete ve Free:** `new` ile heap'te nesne oluşturulurken, `delete` destructor çağırır. `free()` doğrudan bellek serbest bırakır, ancak kaynakları temizlemeden yapması Undefined Behavior'a yol açar.
  - **Delete[]:** Dizilerde ters sırada bellek serbest bırakma güvenli bir yaklaşımdır; destructor'lar tersten çağrılır.
  - **Kopyalama ve Atama:**
    - **Default Constructor:** Varsayılan kopyalama, dinamik bellekle çalışırken sorun çıkarabilir.
    - **Manual Copy Constructor:** Dinamik bellek kullanan sınıflar için gerekli, derin kopyalama yapar.
    - **Assignment Operator:** Varsayılan operatör shallow copy yapar; manuel operatör ise deep copy ile bellek yönetimini sağlar.

- **Kaynaklar:**
  - [GeeksforGeeks - Kapsülleme](https://www.geeksforgeeks.org/encapsulation-in-c/)
  - [LearnCPP - Constructor ve Destructor](https://www.learncpp.com/cpp-tutorial/introduction-to-classes-and-objects/)
  - [YouTube - Yazılımagonulver C++](https://youtube.com/playlist?list=PLfs1gAT4S8yInGkovwucGKCjcxP-Odf7Q)

---

### [**Cpp01: Bellek Yönetimi, İşaretçiler ve Referanslar**](https://github.com/menasy/CPP_Module/tree/main/Cpp01)
- **Öğrenilenler:**
  - Dinamik bellek yönetimi (`new`, `delete`).
  - Yüzeysel (shallow) ve derin (deep) kopyalamanın farkları.
  - Rvalue ve Lvalue referanslar ile çalışma.
  - `delete[]` kullanımında dizilerin sondan başlanarak serbest bırakılması.

- **Notlar:**
  - **Shallow Copy (Yüzeysel Kopya):** Nesneler aynı bellek adresini paylaşır. Bir nesnede yapılan değişiklik diğerini de etkiler.
  - **Deep Copy (Derin Kopya):** Nesneler arasında tam kopyalama yapılır; her nesne farklı bellek adresine sahiptir.
  - **Operator Overloading (Operatör Aşırı Yükleme):**
    - Operatörler, kullanıcı tanımlı sınıflarda aşırı yüklenebilir.
    - Tek bir nesne üzerinde de aşırı yükleme yapılabilir.
  - **Rvalue ve Lvalue Referansları:**
    - **Lvalue:** Adresi tutulabilen değerlerdir (örneğin, değişkenler).
    - **Rvalue:** Geçici değerlerdir (örneğin, literaller).
    - `&&` ile rvalue referansları, geçici değerlerin ömrünü uzatır.

- **Kaynaklar:**
  - [GeeksforGeeks - Shallow ve Deep Copy](https://www.geeksforgeeks.org/shallow-copy-and-deep-copy-in-c/)
  - [LearnCPP - Bellek Yönetimi](https://www.learncpp.com/cpp-tutorial/dynamic-memory-allocation-with-new-and-delete/)
  - [YouTube - Yazılımbilimi C++](https://youtube.com/playlist?list=PLfs1gAT4S8yInGkovwucGKCjcxP-Odf7Q)

---

### [**Cpp02: Polimorfizm, Kayan ve Sabit Noktalı Sayılar**](https://github.com/menasy/CPP_Module/tree/main/Cpp02)
- **Öğrenilenler:**
  - Operatör aşırı yükleme ile kullanıcı tanımlı işlemler.
  - Varsayılan (default) ve kullanıcı tanımlı kopyalama yapıcılar.
  - IEEE 754 standardı ile kayan nokta sayıların temsili.

- **Notlar:**
  - **Kayan Noktalı Sayılar:**
    - IEEE 754 standardında üç bileşen vardır:
      - **İşaret:** Pozitif veya negatiflik.
      - **Exponent:** Üs, sayının büyüklüğünü belirtir.
      - **Mantissa:** Kesirli kısmı temsil eder.
    - Kayan noktalı sayılar büyük bir hassasiyet sağlar ancak yuvarlama hatalarına açıktır.
  - **Sabit Noktalı Sayılar:**
    - Tam sayılar üzerinden işlem yaparak performans avantajı sunar.
    - Bellek verimliliği sağlar ancak yuvarlama hatalarına sebep olabilir.

- **Kaynaklar:**
  - [GeeksforGeeks - Operatör Aşırı Yükleme](https://www.geeksforgeeks.org/operator-overloading-cpp/)
  - [LearnCPP - Floating Point Numbers](https://www.learncpp.com/cpp-tutorial/floating-point-numbers/)
  - [IEEE 754 Standardı](https://www.geeksforgeeks.org/ieee-standard-754-floating-point-numbers/)

---

### [**Cpp03: Kalıtım ve Sanal Fonksiyonlar**](https://github.com/menasy/CPP_Module/tree/main/Cpp03)
- **Öğrenilenler:**
  - Çoklu kalıtım ve sanal miras yapıları.
  - Kalıtımda constructor ve destructor sıralamaları.
  - Sanal tabloların (VTable) mekanizması.

- **Notlar:**
  - **Çift Miras (Multiple Inheritance):**
    - Problem: Aynı temel sınıfın birden fazla kez türetilmesi belirsizlik yaratır.
    - Çözüm: Sanal miras ile temel sınıfın yalnızca bir örneği saklanır.
  - **Constructor ve Destructor Sıralamaları:**
    - Constructor çağrıldığında önce temel sınıfın constructor’ı çalışır.
    - Destructor çağrıldığında önce türetilmiş sınıfın destructor’ı çalışır.
  - **Atama Operatörleri:**
    - **Upcasting:** Türetilmiş sınıf, temel sınıfa atanabilir.
    - **Ters Yönlü Atama:** Temel sınıf türetilmiş sınıfa atanamaz.

![Inheritance Access](https://github.com/menasy/Project_icons/blob/main/Cpp_ModuleImages/InheritanceAccess.png)

- **Kaynaklar:**
  - [JavatPoint - Çoklu Kalıtım](https://www.javatpoint.com/cpp-inheritance)
  - [GeeksforGeeks - Kalıtımda Constructor ve Destructor](https://www.geeksforgeeks.org/order-constructor-destructor-call-c/)
  - [LearnCPP - Virtual Inheritance](https://www.learncpp.com/cpp-tutorial/virtual-base-classes/)

---

### [**Cpp04: Polimorfizm, Sanal Fonksiyonlar ve Soyut Sınıflar**](https://github.com/menasy/CPP_Module/tree/main/Cpp04)
- **Öğrenilenler:**
  - Soyut sınıflar ve saf sanal fonksiyonlar.
  - Dinamik bağlama ile sanal fonksiyonların çalışması.
  - Polimorfizm için sanal yıkıcıların önemi.

- **Notlar:**
  - **Polimorfizm ve Sanal Fonksiyonlar:**
    - İşaretçi veya referans kullanılarak dinamik bağlama yapılabilir.
    - Sanal tablo (VTable), doğru türetilmiş sınıf fonksiyonunun çağrılmasını sağlar.
  - **Soyut Sınıflar ve Saf Sanal Fonksiyonlar:**
    - Soyut sınıflar örneklenemez, saf sanal fonksiyonlar türetilmiş sınıfta tanımlanmalıdır.
  - **Interface ve Saf Soyut Sınıflar:**
    - C++ arayüzleri saf soyut sınıflarla yapılır ve yalnızca metotlar içerir, üye değişkenlere sahip olamaz.

![Virtual Table](https://github.com/menasy/Project_icons/blob/main/Cpp_ModuleImages/VirtualTable.png)
![Virtual Table 2](https://github.com/menasy/Project_icons/blob/main/Cpp_ModuleImages/VirtualTable2.png)

- **Kaynaklar:**
  - [GeeksforGeeks - Polimorfizm ve Sanal Fonksiyonlar](https://www.geeksforgeeks.org/cpp-polymorphism/)
  - [LearnCPP - Abstract Classes](https://www.learncpp.com/cpp-tutorial/pure-virtual-functions-abstract-base-classes-and-interface-classes/)

---

## **Genel Kaynaklar**
- [GeeksforGeeks](https://www.geeksforgeeks.org)
- [LearnCPP](https://www.learncpp.com)
- [YouTube - Yazılımagonulver C++](https://youtube.com/playlist?list=PLfs1gAT4S8yInGkovwucGKCjcxP-Odf7Q)
- [YouTube - Yazılımbilimi C++](https://youtube.com/playlist?list=PLfs1gAT4S8yInGkovwucGKCjcxP-Odf7Q)
