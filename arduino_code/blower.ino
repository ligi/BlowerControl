
const int outputs=4;

const int on_times[]={1,2,3,4};
const int off_times[]={10,10,10,10};

unsigned long set_time[outputs];
long set_state[outputs];


void setup() {
  for (int i=0;i<outputs;i++) {
    pinMode(i, OUTPUT);   
    set(i,LOW);
  }   
}

void loop()
{
  unsigned long currentMillis = millis();
  
  for (int i=0;i<outputs;i++) {
    unsigned long diff=currentMillis-set_time[i];
    if (set_state[i]==LOW) {
      if ((diff/1000)>off_times[i]) {
        set(i,HIGH);
      }
    } else {
      if ((diff/1000)>on_times[i]) {
        set(i,LOW);
      }
      
    }
  }   
  
  delay(1000);
  
}

void set(int pos,int state) {
   set_time[pos] = millis();
   digitalWrite(pos, state);
   set_state[pos]= state;
}
