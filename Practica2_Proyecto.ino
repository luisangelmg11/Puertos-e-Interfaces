const int btn = 7;   // Pin del botón
const int buzz = 11;  // Pin del buzzer

// Frecuencias de las notas (en Hz)
#define G  391    // Sol
#define A  440    // La
#define B  493    // Si
#define C5 523    // Do
#define D5 587    // Re
#define E5 659    // Mi

// Duraciones de las notas
#define WHOLE 1000
#define HALF 500
#define QUARTER 250
#define EIGHTH 125

void setup() {
  pinMode(btn, INPUT);
  pinMode(buzz, OUTPUT);
}

void loop() {
  if (digitalRead(btn)) {
    // Fragmento de "La canción de cuando pierdes" (simplificada)
    playNote(G, QUARTER);   // Sol
    playNote(A, QUARTER);   // La
    playNote(B, QUARTER);   // Si
    playNote(C5, QUARTER);  // Do
    playNote(B, QUARTER);   // Si
    playNote(A, QUARTER);   // La
    playNote(G, HALF);      // Sol

    playNote(D5, QUARTER);  // Re
    playNote(C5, QUARTER);  // Do
    playNote(B, QUARTER);   // Si
    playNote(A, HALF);      // La
    playNote(G, WHOLE);     // Sol

    delay(1000);  // Pausa antes de repetir la canción
  } else {
    noTone(buzz);
  }
}

// Función para tocar una nota con su duración
void playNote(int note, int duration) {
  tone(buzz, note);  
  delay(duration);   
  noTone(buzz);      
  delay(50);         
}



