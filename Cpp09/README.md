# CPP09 - STL (Standard Template Library)

Bu modül, C++ programlama dilinin güçlü kütüphanesi olan STL'in (Standard Template Library) kullanımını öğrenmeyi ve farklı konteynerler arasındaki performans farklarını anlamayı amaçlamaktadır. Modül, üç farklı alıştırma içermekte ve her birinde farklı STL konteynerlerinin kullanılmasını gerektirmektedir.

## Genel Bakış

STL, C++ programlama dilinin sunduğu, veri yapılarını ve algoritmaları içeren kapsamlı bir kütüphanedir. Bu modülde, STL konteynerlerinin farklı senaryolarda nasıl kullanılacağını ve her birinin performans özelliklerini inceleyeceğiz.

## Alıştırmalar

### Exercise 00: Bitcoin Exchange

Bu alıştırmada, belirli bir tarihte belirli miktardaki bitcoinin değerini hesaplayan bir program geliştirmemiz isteniyor. Program, CSV formatında bir veritabanını kullanarak tarihe göre bitcoin değerlerini bulacak ve kullanıcının belirttiği miktarlarla çarparak sonuçları gösterecektir.

### Exercise 01: Reverse Polish Notation (RPN)

Ters Polonya Notasyonu (RPN), operatörlerin işlenenlerden sonra geldiği bir matematiksel gösterim şeklidir. Bu alıştırmada, RPN formatında verilen matematiksel ifadeleri hesaplayan bir program geliştireceğiz. Program, komut satırından alınan RPN ifadesini işleyerek sonucu hesaplayacaktır.

### Exercise 02: PmergeMe

Son alıştırmada, Ford-Johnson (Merge-Insertion) sıralama algoritmasını kullanarak bir sıralama programı geliştirmemiz gerekiyor. Bu program iki farklı STL konteyneri kullanacak ve her iki konteyner için de sıralama sürelerini ölçecektir.

## Ford-Johnson Algoritması (Merge-Insertion Sort)

Ford-Johnson algoritması, karşılaştırma sayısını minimize etmeyi amaçlayan gelişmiş bir sıralama algoritmasıdır. Teorik olarak, özellikle küçük veri setleri için optimal sıralama algoritmasıdır.

### Algoritmanın Çalışma Mantığı

Ford-Johnson algoritması, sıralama problemini "karşılaştırmaların sayısını minimize etme" bağlamında ele alır. Temel adımları şu şekildedir:

1. **Çiftleme (Pairing):**
   - Diziyi çiftler halinde grupla
   - Her çiftte elemanları karşılaştırarak bir "kazanan" (büyük) ve bir "kaybeden" (küçük) belirle

2. **Kazanan ve Kaybeden Listeleri:**
   - Kazananlardan oluşan bir liste oluştur
   - Kaybedenlerden oluşan bir liste oluştur
   - Eğer eleman sayısı tek ise, bir eleman tek başına kalır

3. **Kazananların Sıralanması:**
   - Kazananlar listesini (daha az eleman içerdiği için) yeniden sırala
   - Bu adımda yine Ford-Johnson algoritması kullanılabilir (özyinelemeli yaklaşım)

4. **Kaybedenlerin Optimal Yerleştirilmesi:**
   - Kaybeden elemanları, en az karşılaştırma yaparak sıralı kazananlar listesine yerleştir
   - Bu adım, algoritmanın en kritik kısmıdır ve optimal yerleştirme sırası kullanır

### Somut Örnek

Aşağıdaki örnek, algoritmanın çalışmasını adım adım göstermektedir:

**Başlangıç dizisi:** [3, 5, 9, 7, 4]

1. **Çiftleme ve Karşılaştırma:**
   - Çift 1: (3, 5) → 3 < 5 → Kazanan: 5, Kaybeden: 3
   - Çift 2: (9, 7) → 9 > 7 → Kazanan: 9, Kaybeden: 7
   - Tek kalan: 4

2. **Kazanan ve Kaybeden Listeleri:**
   - Kazananlar: [5, 9]
   - Kaybedenler: [3, 7]
   - Tek kalan: [4]

3. **Kazananların Sıralanması:**
   - [5, 9] (Bu durumda zaten sıralı)

4. **Kaybedenlerin Yerleştirilmesi:**
   - İlk olarak 3'ü yerleştir: 3 < 5 → [3, 5, 9]
   - Sonra 7'yi yerleştir: 5 < 7 < 9 → [3, 5, 7, 9]
   - Son olarak 4'ü yerleştir: 3 < 4 < 5 → [3, 4, 5, 7, 9]

**Sonuç:** [3, 4, 5, 7, 9]

### Konteyner Performans Farkları

Ford-Johnson algoritması, özellikle ekleme (insertion) işlemleri sırasında farklı konteynerler üzerinde farklı performans gösterebilir:

#### std::list vs std::deque

**std::list:**
- Çift yönlü bağlı liste yapısına sahiptir
- Ekleme işlemleri O(1) karmaşıklığındadır
- Eleman yerleştirmek için sadece pointer'ları değiştirmek yeterlidir
- Yerleştirme sırasında diğer elemanları kaydırmaya gerek yoktur

**std::deque:**
- Sabit boyutlu bloklardan oluşan bir yapıdır
- Ortaya eleman ekleme işlemleri, ilgili blok içindeki elemanların kaydırılmasını gerektirebilir
- Random erişim sağlar ancak orta noktalara ekleme işlemi daha maliyetlidir

Bu yüzden, Ford-Johnson algoritmasında kaybeden elemanların sıralı kazananlar listesine eklenmesi adımında, std::list daha verimli çalışabilir. Pratikte, bu durum std::list'in daha hızlı sonuçlar vermesine neden olabilir.

## Özetle

Bu modül, farklı STL konteynerlerinin güçlü ve zayıf yönlerini anlamak ve Ford-Johnson gibi gelişmiş bir sıralama algoritmasını uygulamak için mükemmel bir fırsattır. Her bir alıştırma, farklı konteyner türlerinin kullanımını gerektirerek, STL'in sunduğu çeşitli veri yapılarını derinlemesine öğrenmemize olanak sağlamaktadır.