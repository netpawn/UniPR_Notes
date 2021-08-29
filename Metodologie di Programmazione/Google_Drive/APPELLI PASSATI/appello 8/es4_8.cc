//Una applicazione di rete prevede la gestione di sessioni di comunicazione di due tipologie distinte, ognuna caratterizzata da uno specifico protocollo di comunicazione. Siccome i due protocolli hanno
alcune somiglianze (in termini di dati memorizzati e di operazioni di basso livello da eseguire), il programmatore ha usato il seguente progetto per incapsulare le parti comuni in una classe BasicProtocol:

class BasicProtocol {
 private:
 /*...*/
 public:
 BasicProtocol();
 virtual ~BasicProtocol();
 bool BasicMsgA( /*...*/ );
 bool BasicMsgB( /*...*/ );
 bool BasicMsgC( /*...*/ );
};
 
class Protocol1 : public BasicProtocol {
  public:
 Protocol1();
 ~Protocol1();
 bool DoMsg1( /*...*/ );
 bool DoMsg2( /*...*/ );
 bool DoMsg3( /*...*/ );
};

class Protocol2 : public BasicProtocol {
 public:
  Protocol2();
  ~Protocol2();
  bool DoMsg1( /*...*/ );
  bool DoMsg2( /*...*/ );
  bool DoMsg3( /*...*/ );
  bool DoMsg4( /*...*/ );
  bool DoMsg5( /*...*/ );
};

//Le funzioni membro delle classi derivate invocano le funzioni della classe base quando necessario, ma gestiscono la trasmissione indipendentemente.
//In particolare, gli utenti della gerarchia di classi tipicamente decidono di utilizzare uno dei due protocolli specifici. 
//Discutere brevemente se il progetto delle classi suddette è appropriato rispetto all’uso che ne viene fatto. 
//Elencare le eventuali modifiche da apportare, indicandone i motivi.


class BasicProtocol {
 private:
 /*...*/
 public:
 BasicProtocol();
 virtual ~BasicProtocol();
 bool BasicMsgA( /*...*/ );
 bool BasicMsgB( /*...*/ );
 bool BasicMsgC( /*...*/ );
 virtual bool DoMsg1( /*...*/ )=0;
 virtual bool DoMsg2( /*...*/ )=0;
 virtual bool DoMsg3( /*...*/ )=0;
}
};
 
class Protocol1 : public BasicProtocol {
  public:
 Protocol1();
 ~Protocol1();
 bool DoMsg1( /*...*/ );
 bool DoMsg2( /*...*/ );
 bool DoMsg3( /*...*/ );
};

class Protocol2 : public BasicProtocol {
 public:
  Protocol2();
  ~Protocol2();
  bool DoMsg1( /*...*/ );
  bool DoMsg2( /*...*/ );
  bool DoMsg3( /*...*/ );
  bool DoMsg4( /*...*/ );
  bool DoMsg5( /*...*/ );
};
