int a = 1, b = 2, c = 3, d = 4, e = 5, f = 6, g = 7, dg1 = 8, dg2 = 9;

// Array pola angka 0-9 untuk 7-segment display
const int numbers[10][7] = {
  {LOW, LOW, LOW, LOW, LOW, LOW, HIGH},  // 0
  {HIGH, LOW, LOW, HIGH, HIGH, HIGH, HIGH},  // 1
  {LOW, LOW, HIGH, LOW, LOW, HIGH, LOW},  // 2
  {LOW, LOW, LOW, LOW, HIGH, HIGH, LOW},  // 3
  {HIGH, LOW, LOW, HIGH, HIGH, LOW, LOW},  // 4
  {LOW, HIGH, LOW, LOW, HIGH, LOW, LOW},  // 5
  {LOW, HIGH, LOW, LOW, LOW, LOW, LOW},  // 6
  {LOW, LOW, LOW, HIGH, HIGH, HIGH, HIGH},  // 7
  {LOW, LOW, LOW, LOW, LOW, LOW, LOW},  // 8
  {LOW, LOW, LOW, LOW, HIGH, LOW, LOW}  // 9
};

void setup() {
  for (int i = a; i <= g; i++) pinMode(i, OUTPUT);  // Set pin segmen a-g sebagai output
  pinMode(dg1, OUTPUT);  // Digit pertama
  pinMode(dg2, OUTPUT);  // Digit kedua
}

void loop() {
  for (int i = 20; i >= 0; i--) {
    int tens = i / 10;  // Digit puluhan
    int ones = i % 10;  // Digit satuan
    for (int n = 0; n < 300; n++) {  // Looping untuk menjaga tampilan tetap stabil
      displayDigit(dg1, ones);  // Tampilkan digit satuan di dg1 (digit pertama/kiri)
      displayDigit(dg2, tens);  // Tampilkan digit puluhan di dg2 (digit kedua/kanan)
    }
    delay(300);  // Tunggu 1 detik sebelum pindah ke angka berikutnya
  }
}

// Fungsi untuk menampilkan digit pada 7-segment display
void displayDigit(int digitSelect, int num) {
  digitalWrite(digitSelect, LOW);  // Aktifkan digit yang dipilih (dg1 atau dg2)
  for (int i = 0; i < 7; i++) {
    digitalWrite(a + i, numbers[num][i]);  // Tampilkan angka sesuai pola
  }
  delay(5);  // Tambahkan sedikit delay untuk membuat tampilan stabil
  clear();  // Matikan segmen setelah ditampilkan
}

// Fungsi untuk mematikan semua segmen
void clear() {
  for (int i = a; i <= g; i++) {
    digitalWrite(i, HIGH);  // Set semua segmen menjadi HIGH (mati)
  }
  digitalWrite(dg1, HIGH);  // Matikan digit pertama
  digitalWrite(dg2, HIGH);  // Matikan digit kedua
}
