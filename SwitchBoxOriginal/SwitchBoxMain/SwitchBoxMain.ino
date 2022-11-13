
const boolean debug = true;// デバッグ用フラグ

/*
 ピンの番号を設定
*/
const int switchPin0 = 0;
const int switchPin1 = 1;
const int switchPin2 = 2;
const int switchPin3 = 3;
const int switchPin4 = 4;
const int switchPin5 = 5;
const int switchPin6 = 6;
const int switchPin7 = 7;

const int rotoryswitch1N = 8;
const int rotoryswitch1A = 9;
const int rotoryswitch2N = 10;
const int rotoryswitch2A = 11;
const int rotoryswitch3N = 12;
const int rotoryswitch3A = 13;
const int rotoryswitch4N = 19;
const int rotoryswitch4A = 20;
const int rotoryswitch5N = 21;
const int rotoryswitch5A = 22;
const int rotoryswitch6N = 23;
const int rotoryswitch6A = 24;




void setup() {
  // put your setup code here, to run once:

  // シリアル開始（デバックの場合）
  if (debug == true) {
    Serial.begin(9600);
  }

  // シリアル開始の準備が整うまでここで処理を止める。
  while( !Serial ) {
  }

  //初期化
  sendStartMessage("Initialize Strat");
  initialize();
  sendStartMessage("Initialize End");


  sendStartMessage("Loop Method Strat");
}

/*
    初期化
*/
void initialize(){
  
  /*
    ピンが受信か送信かを設定
  */
  pinMode(switchPin0, INPUT);
  pinMode(switchPin1, INPUT);
  pinMode(switchPin2, INPUT);
  pinMode(switchPin3, INPUT);
  pinMode(switchPin4, OUTPUT);
  pinMode(switchPin5, OUTPUT);
  pinMode(switchPin6, OUTPUT);
  pinMode(switchPin7, OUTPUT);

  pinMode(rotoryswitch1N, INPUT);
  pinMode(rotoryswitch1A, INPUT);
  pinMode(rotoryswitch2N, INPUT);
  pinMode(rotoryswitch2A, INPUT);
  pinMode(rotoryswitch3N, INPUT);
  pinMode(rotoryswitch3A, INPUT);
  pinMode(rotoryswitch4N, INPUT);
  pinMode(rotoryswitch4A, INPUT);
  pinMode(rotoryswitch5N, INPUT);
  pinMode(rotoryswitch5A, INPUT);
  pinMode(rotoryswitch6N, INPUT);
  pinMode(rotoryswitch6A, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  sendStartMessage("Switch Status start");

  outputPinStatusMessage(switchPin0,"switchPin0");
  outputPinStatusMessage(switchPin1,"switchPin1");
  outputPinStatusMessage(switchPin2,"switchPin2");
  outputPinStatusMessage(switchPin3,"switchPin3");
  outputPinStatusMessage(switchPin4,"switchPin4");
  outputPinStatusMessage(switchPin5,"switchPin5");
  outputPinStatusMessage(switchPin6,"switchPin6");
  outputPinStatusMessage(switchPin7,"switchPin7");

  outputPinStatusMessage(rotoryswitch1N,"rotoryswich1N");
  outputPinStatusMessage(rotoryswitch1A,"rotoryswich1A");
  outputPinStatusMessage(rotoryswitch2N,"rotoryswich2N");
  outputPinStatusMessage(rotoryswitch2A,"rotoryswich2A");
  outputPinStatusMessage(rotoryswitch3N,"rotoryswich3N");
  outputPinStatusMessage(rotoryswitch3A,"rotoryswich3A");
  outputPinStatusMessage(rotoryswitch4N,"rotoryswich4N");
  outputPinStatusMessage(rotoryswitch4A,"rotoryswich4A");
  outputPinStatusMessage(rotoryswitch5N,"rotoryswich5N");
  outputPinStatusMessage(rotoryswitch5A,"rotoryswich5A");
  outputPinStatusMessage(rotoryswitch6N,"rotoryswich6N");
  outputPinStatusMessage(rotoryswitch6A,"rotoryswich6A");



  sendStartMessage("Switch Status End");
  delay(1000);//1000msec待機(1秒待機)
}


/*
    開始のメッセージ送信（デバッグ用）
*/
void sendStartMessage(String _message){
  if(debug == true){
    Serial.println("----------------- " + _message + " -----------------" );
  }
}

/*
    ピンのステータス取得
*/
void outputPinStatusMessage(int _pinNo, String _pinNmae){
  boolean _pinStatus;
  _pinStatus = digitalRead(_pinNo);
  Serial.println( _pinNmae + " pin status : " + String(_pinStatus));
}
