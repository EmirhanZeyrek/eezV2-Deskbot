eezV2 Deskbot 🤖

An Interactive Desktop Companion Robot

--- English Description --- 

eezV2 Deskbot

eezV2 Deskbot is an open-source, highly interactive desktop companion powered by an Arduino Nano. Unlike simple blink-LED projects, eezV2 uses an advanced State Machine architecture to mimic organic behavior. By combining data from multiple sensors (Touch, Sound, Light), it behaves like a tiny “living” creature—happy when petted, annoyed when squeezed, startled by loud noises, and sleepy in the dark.

✨ Key Features & Behaviors
🎭 Expressive OLED Face
Uses high-performance bitmap rendering to display multiple emotions:
Happy, Angry, Scared, Sleepy, Neutral/Idle.

🧠 Sensor Fusion Logic
Touch Response (TTP223):
Short taps = Happy
Long press = Angry + head-shake animation

Sound Reaction (Microphone):
Detects sudden loud noises → triggers Startle + Look Around behavior

Light Detection (LDR):
Detects darkness → enters Sleep Mode

👀 Physical Animation
A single SG90 servo animates head movement according to emotion or gaze direction.

🔊 Dynamic Audio Feedback
A passive buzzer generates expressive R2-D2-style beeps and chirps depending on emotional state.

⚡ Memory Optimization
Optimized for ATmega328P’s limited RAM using:

Page Buffer Rendering

PROGMEM Bitmap Storage

| Component                      | Function              | Pin              |
| ------------------------------ | --------------------- | ---------------- |
| **Arduino Nano**               | Main controller       | —                |
| **1.3" OLED Display (SH1106)** | Eyes / UI             | SDA: A4, SCL: A5 |
| **SG90 Servo**                 | Head movement         | D3 (PWM)         |
| **KY-037 Microphone**          | Sound detection       | A1               |
| **TTP223 Touch Sensor**        | Interaction input     | D7               |
| **LDR**                        | Light detection       | A0               |
| **Passive Buzzer**             | Audio output          | D6               |
| **MT3608 Boost Converter**     | 3.7V → 5V             | 5V pin           |
| **18650 Battery**              | Main power            | —                |
| **220µF+ Capacitor**           | Servo power stability | 5V ↔ GND         |

📂 Software Architecture

The project follows clean Object-Oriented Programming principles:

eezV2_1.ino → Setup + main loop

eyes.h → Class declarations, state enums, pin definitions

eyes.cpp → Full state machine logic, drawing functions, sensor processing

--- TÜKÇE AÇIKLAMA --- 
eezV2 Deskbot

eezV2 Deskbot, Arduino Nano tabanlı, etkileşimli ve açık kaynaklı bir masaüstü robotudur. Basit LED projelerinin aksine, gelişmiş bir Durum Makinesi (State Machine) mimarisi kullanır. Dokunma, Ses ve Işık sensörlerinden gelen verileri birleştirerek daha “organik” davranışlar sergiler. Sevilince mutlu olur, çok sıkıştırılırsa kızar, ani seslerde irkilir ve karanlıkta uyur.

✨ Temel Özellikler ve Davranışlar

🎭 İfadeli OLED Yüz
Bitmap render yöntemiyle şu duyguları gösterir:
Mutlu, Kızgın, Korkmuş, Uykulu, Nötr

🧠 Sensör Füzyonu
Dokunmatik Tepkisi (TTP223):
Kısa dokunuş = Mutlu
Uzun basılı tutma = Kızgın + kafa sallama

Ses Algılama (Mikrofon):
Ani yüksek ses → İrkilme + Etrafa Bakma

Işık Algılama (LDR):
Karanlık → Uyku Modu

👀 Fiziksel Animasyon
SG90 servo, robotun bakış yönünü fiziksel hareketle destekler.

🔊 İşitsel Geri Bildirim
Pasif buzzer ile duruma göre robotik “bip” ve “ciyk” sesleri üretir.

⚡ Hafıza Optimizasyonu
ATmega328P’nin 2KB RAM sınırları için optimize edilmiştir:

Sayfa Tamponlama (Page Buffer)

PROGMEM kullanımı

| Bileşen                | Görev             | Pin              |
| ---------------------- | ----------------- | ---------------- |
| **Arduino Nano**       | Ana kontrolcü     | —                |
| **1.3" OLED (SH1106)** | Yüz/Arayüz        | SDA: A4, SCL: A5 |
| **SG90 Servo**         | Kafa hareketi     | D3               |
| **KY-037 Mikrofon**    | Ses algılama      | A1               |
| **TTP223 Dokunmatik**  | Etkileşim         | D7               |
| **LDR**                | Işık algılama     | A0               |
| **Pasif Buzzer**       | Ses               | D6               |
| **MT3608**             | Voltaj yükseltici | 5V               |
| **18650 Pil**          | Güç               | —                |
| **220µF+ Kapasitör**   | Servo kararlılığı | 5V ↔ GND         |

📄 License / Lisans
Distributed under the MIT License.
See the LICENSE file for details.

Bu proje MIT Lisansı ile dağıtılmaktadır.
Detaylar için LICENSE dosyasına bakabilirsiniz.
