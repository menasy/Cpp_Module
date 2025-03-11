# C++ Module 05 - İstisna İşleme (Exception Handling)

Bu modül, C++ programlama dilindeki istisna işleme (exception handling) mekanizmalarını anlama ve uygulama becerilerini geliştirmeye odaklanmaktadır. Modül, bürokrasi temalı bir senaryo üzerinden try-catch blokları, özel istisna sınıfları ve istisna yönetimini uygulamalı olarak öğretmeyi amaçlar.

## İçerik

Module 05, dört egzersizden oluşmaktadır:

1. **Exercise 00: Mommy, when I grow up, I want to be a bureaucrat!**
   - Temel bir `Bureaucrat` sınıfının oluşturulması
   - Bürokratların 1 (en yüksek) ile 150 (en düşük) arasında dereceleri vardır
   - Özel istisna sınıflarının tanımlanması (GradeTooHighException, GradeTooLowException)
   - Nesne oluşturma ve metodları çağırma sırasında istisnaların fırlatılması

2. **Exercise 01: Form up, maggots!**
   - `Form` sınıfının oluşturulması
   - Formların sabit bir ismi, imzalı olup olmadığını belirten bir boolean değeri, imzalamak ve uygulamak için gereken minimum dereceler vardır
   - Bürokrat ve form arasındaki etkileşimlerin yönetilmesi
   - Form imzalama süreçlerinde istisna kontrolü

3. **Exercise 02: No, you need form 28B, not 28C...**
   - Soyut bir `AForm` temel sınıfının oluşturulması
   - Farklı işlevlere sahip somut form sınıflarının geliştirilmesi:
     - **ShrubberyCreationForm**: İmza derecesi 145, uygulama derecesi 137. Çalışma dizininde ASCII ağaçları içeren `<hedef>_shrubbery` dosyası oluşturur.
     - **RobotomyRequestForm**: İmza derecesi 72, uygulama derecesi 45. Delme sesleri çıkarır ve %50 olasılıkla hedefin başarıyla robotlaştırıldığını bildirir, aksi halde başarısız olduğunu belirtir.
     - **PresidentialPardonForm**: İmza derecesi 25, uygulama derecesi 5. Hedefin Zaphod Beeblebrox tarafından affedildiğini bildirir.
   - Form uygulaması için izin kontrolü ve istisna yönetimi

4. **Exercise 03: At least this beats coffee-making**
   - Form oluşturmak için bir `Intern` sınıfının geliştirilmesi
   - İsim veya derecelendirme olmaksızın, sadece istenilen form tipini ve hedefini alarak uygun formu oluşturan `makeForm()` fonksiyonu
   - Factory pattern uygulaması
   - Dinamik nesne oluşturma

## Bürokrasi Sistemindeki Sınıflar ve İlişkileri

### Bureaucrat (Bürokrat)
- Sabit bir isim ve 1-150 arasında bir dereceye sahiptir
- Derecenin geçersiz olması durumunda `GradeTooHighException` veya `GradeTooLowException` fırlatır
- Derecesi 1 en yüksek, 150 en düşük derecedir (1 > 2)
- Derecesini artırma ve azaltma fonksiyonları vardır
- Form imzalama yeteneğine sahiptir (`signForm()` metodu)
- Formları uygulama yeteneğine sahiptir (`executeForm()` metodu)

### Form ve AForm
- `Form` sınıfı başlangıçta temel bir form yapısı sağlar
- `AForm` (Abstract Form) daha sonra soyut bir temel sınıf olarak kullanılır
- Her formun sabit bir ismi, imzalı olup olmadığını belirten bir durumu, imzalamak ve uygulamak için gereken minimum dereceleri vardır
- Formların imzalanması için `beSigned()` metodu bulunur
- Formların uygulanması için `execute()` metodu bulunur

### Özel Form Türleri
1. **ShrubberyCreationForm**
   - İmza derecesi: 145, uygulama derecesi: 137
   - İşlev: Çalışma dizininde `<hedef>_shrubbery` adlı bir dosya oluşturur ve içine ASCII formatında ağaç çizimleri yerleştirir
   - Örnek: "home" hedefi için "home_shrubbery" dosyası oluşturur

2. **RobotomyRequestForm**
   - İmza derecesi: 72, uygulama derecesi: 45
   - İşlev: Delme sesleri çıkarır ve %50 olasılıkla hedefin başarıyla robotlaştırıldığını bildirir, başarısız olduğunda ise robotlaştırma işleminin başarısız olduğunu belirtir
   - Örnek: "Bender" hedefi için "Bender has been robotomized successfully" veya "Robotomy failed" mesajı

3. **PresidentialPardonForm**
   - İmza derecesi: 25, uygulama derecesi: 5
   - İşlev: Hedefin Zaphod Beeblebrox tarafından affedildiğini bildirir (Hitchhiker's Guide to the Galaxy referansı)
   - Örnek: "Criminal" hedefi için "Criminal has been pardoned by Zaphod Beeblebrox" mesajı

### Intern (Stajyer)
- İsmi, derecesi veya özel karakteristiği olmayan bir sınıf
- `makeForm()` metodu ile form adı ve hedef bilgisini alarak uygun form nesnesini oluşturur
- Form oluşturma işlemini basitleştiren bir fabrika (factory) görevi görür
- Geçersiz form adı için hata mesajı verir

## İstisna İşleme Hakkında Temel Bilgiler

### Try-Catch Mekanizması

C++'da istisna işleme, programın çalışması sırasında oluşabilecek hataları ele almanın yapılandırılmış bir yoludur. Bu mekanizma şu bileşenlerden oluşur:

```cpp
try {
    // Hata oluşabilecek kod
    if (problem_detected) {
        throw exception_object;  // İstisna fırlatma
    }
} catch (exception_type& e) {
    // İstisnayı ele alma kodu
}
```

### İstisna İşleme Süreci

1. **Try Bloğu**: Potansiyel olarak istisna fırlatabilecek kodu içerir.
2. **Throw İfadesi**: Bir hata durumunda istisna nesnesi fırlatır.
3. **Catch Bloğu**: Fırlatılan istisnaları yakalar ve işler.

### Arka Planda Çalışma Mantığı

1. **Stack Unwinding (Yığın Çözülmesi)**:
   - `throw` ifadesi çalıştırıldığında, program uygun bir `catch` bloğu bulana kadar çağrı yığınında yukarıya doğru ilerler.
   - Bu süreçte, çağrı yığınındaki her fonksiyonun yerel nesnelerinin yıkıcıları (destructors) çağrılır.

2. **Exception Table**:
   - Derleyici, her fonksiyon için hangi istisnaların yakalanacağını ve nasıl işleneceğini belirten bir istisna tablosu oluşturur.
   - Bu tablo, runtime sırasında hangi `catch` bloğuna atlanacağını belirlemek için kullanılır.

3. **terminate() ve unexpected()**:
   - Eğer uygun bir `catch` bloğu bulunamazsa, `terminate()` fonksiyonu çağrılır ve program sonlandırılır.
   - Eğer bir fonksiyon, belirttiği türlerden farklı bir istisna fırlatırsa, `unexpected()` fonksiyonu çağrılır.

### Özel İstisna Sınıfları

C++, programcılara kendi istisna sınıflarını tanımlama olanağı sunar. Bu sınıflar genellikle `std::exception` sınıfından türetilir:

```cpp
class MyException : public std::exception {
public:
    const char* what() const throw() {
        return "Özel istisna mesajı";
    }
};
```

## Uygulama İpuçları

1. İstisna sınıflarını `std::exception` sınıfından türetmek, `what()` metodunu kullanarak anlamlı hata mesajları sağlar.
2. İstisnaları yakaladıktan sonra programın normal akışına devam etmesini sağlamak için uygun hata işleme kodu yazılmalıdır.
3. İstisnaları fırlatırken, kodun anlaşılabilirliğini artırmak için açıklayıcı mesajlar kullanılmalıdır.
4. Sınıf hiyerarşilerinde istisna yönetimini dikkatle planlamak, kodun bakımını kolaylaştırır.

## Kaynaklar

- [BilgiGunlugum - C++ Exception](https://www.bilgigunlugum.net/prog/cppprog/cpp_exception)