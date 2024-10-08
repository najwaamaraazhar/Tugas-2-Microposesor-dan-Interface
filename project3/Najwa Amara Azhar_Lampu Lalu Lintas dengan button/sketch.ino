byte hijau = 11;
byte kuning = 12;
byte merah = 13;
byte tombol = 2;

bool bolehMenyebrang = false;

byte pinD1 = 0; // Digit puluhan
byte pinD2 = 1; // Digit satuan
byte pinA = 3;
byte pinB = 4;
byte pinC = 5;
byte pinD = 6;
byte pinE = 7;
byte pinF = 8;
byte pinG = 9;

const byte angka[10][7] = {
    {HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, LOW},   // 0
    {LOW, HIGH, HIGH, LOW, LOW, LOW, LOW},       // 1
    {HIGH, HIGH, LOW, HIGH, HIGH, LOW, HIGH},    // 2
    {HIGH, HIGH, HIGH, HIGH, LOW, LOW, HIGH},     // 3
    {LOW, HIGH, HIGH, LOW, LOW, HIGH, HIGH},     // 4
    {HIGH, LOW, HIGH, HIGH, LOW, HIGH, HIGH},    // 5
    {HIGH, LOW, HIGH, HIGH, HIGH, HIGH, HIGH},    // 6
    {HIGH, HIGH, HIGH, LOW, LOW, LOW, LOW},       // 7
    {HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH},   // 8
    {HIGH, HIGH, HIGH, HIGH, LOW, HIGH, HIGH}     // 9
};

void setup() {
    pinMode(hijau, OUTPUT);
    pinMode(kuning, OUTPUT);
    pinMode(merah, OUTPUT);
    pinMode(tombol, INPUT);
    
    attachInterrupt(digitalPinToInterrupt(tombol), mauMenyebrang, RISING);
    
    pinMode(pinD1, OUTPUT);
    pinMode(pinD2, OUTPUT);
    
    for (byte i = pinA; i <= pinG; i++) {
        pinMode(i, OUTPUT);
    }
}

void loop() {
    if (bolehMenyebrang) {
        menyebrang();
        bolehMenyebrang = false;
    } else {
        hijauKedip();
    }
}

void hijauKedip() {
    digitalWrite(hijau, HIGH);
    delay(200);
    digitalWrite(hijau, LOW);
    delay(200);
}

void menyebrang() {
    digitalWrite(merah, LOW);
    digitalWrite(hijau, LOW);
    digitalWrite(kuning, HIGH);
    delay(2000);
    
    digitalWrite(merah, HIGH);
    digitalWrite(kuning, LOW);

    for (int n = 20; n >= 0; n--) {
        for (int m = 0; m < 500; m++) {
            digit1(n / 10); // Puluhan
            digit2(n % 10); // Satuan
            delay(1);       // Delay untuk stabilisasi
            clear();
        }
    }
    
    digitalWrite(hijau, HIGH);
    delay(2000);
    digitalWrite(hijau, LOW);
}

void mauMenyebrang() {
    bolehMenyebrang = true;
}

void digit1(byte num) {
    digitalWrite(pinD1, LOW); // Menyalakan digit pertama
    digitalWrite(pinD2, HIGH); // Mematikan digit kedua
    setAngka(num);             // Menampilkan angka
}

void digit2(byte num) {
    digitalWrite(pinD1, HIGH); // Mematikan digit pertama
    digitalWrite(pinD2, LOW);  // Menyalakan digit kedua
    setAngka(num);             // Menampilkan angka
}

void setAngka(byte num) {
    digitalWrite(pinA, angka[num][0]);
    digitalWrite(pinB, angka[num][1]);
    digitalWrite(pinC, angka[num][2]);
    digitalWrite(pinD, angka[num][3]);
    digitalWrite(pinE, angka[num][4]);
    digitalWrite(pinF, angka[num][5]);
    digitalWrite(pinG, angka[num][6]);
}

void clear() {
    for (byte i = pinA; i <= pinG; i++) {
        digitalWrite(i, LOW);
    }
    delay(1);
}
