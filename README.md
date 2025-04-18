# NotaFiscalPaulista
Projeto que cria um dispositivo (hardware) e app para Android para auxiliar ONGs a cadastrar notas fiscais para ajudar na captação de recursos.

Este projeto é constituído de um hardware usando arduino pro mini versão Leonardo ou compatível com processador Atmega32u4, um módulo bluetooth hc-05, hc-06 ou similar e um app que interpreta os qrcodes dos cupons fiscais. Após a leitura sem erro e interpretação, o código de 44 digitos é separado e enviado do APP para o hardware que vai atuar como um teclado e um mouse. Após o envio dos 44 dígitos é enviado um ENTER e um clique para auxiliar na operação com o site da [Nota Fiscal Paulista](https://www.nfp.fazenda.sp.gov.br/Inicio.aspx).

Este projeto pode ser adaptado para qualquer sistema similar de outros estados.

# Construção do hardware
Por definição o hardwware consta de uma placa Arduino pro mini com micro-controlador Atmega32u4 que recebe alimentação e faz comunicação com o PC Windows ou Linux. Por definição também os pinos 8 e 9 do Arduino são ligados no módulo bluetooth conforme lista abaixo:

<table>
  <thead>
    <td>Arduino</td><td>Módulo Bluetooth</td>
  </thead>
  <tbody>
    <tr><td>pin 8 (TX)</td><td>RX</td></tr>
    <tr><td>pin 9 (RX)</td><td>TX</td></tr>
    <tr><td>VCC</td><td>VCC</td></tr>
    <tr><td>GND</td><td>GND</td></tr>
  </tbody>
</table>

OBS.: verifique a tensão de cada módulo para evitar queima do componente.

Nos sites abaixo é possível encontrar tutoriais de como mudar o nome do seu módulo Bluetooth (sugestão: use TECLADONFP):

https://www.martyncurrey.com/hc-06-hc01-comv2-0/

https://www.youtube.com/watch?app=desktop&v=s-lzV_RfZoo - para modulo JDY-31

A montagem cabe numa caixinha plástica de pelo menos 6 x 4 x 2 cm. É preciso realizar furações para export os leds e o conector usb da placa Arduino.

Um cabo micro usb ou usb-c é necessário para ligar o arduino ao pc/notebook.

# Firmware
Como a comunicação serial nativa do Arduino é usada para comunicar com o PC, a solução é usar o pacote SoftSerial para usar os pinos 8 e 9 como uma interface serial para comunicar  com o módulo Bluetooth. Os pinos 8 e 9 foram usados por definição neste projeto, porém poderiam ser utilizados outros. No site da [documentação do Arduino](https://docs.arduino.cc/libraries/) procure por SoftwareSerial para mais detalhes. Também são utilizadas bibliotecas Mouse e Keyboard que fazem parte da distribuição padrão da Arduino IDE.

Baixe a [IDE Arduino](https://www.arduino.cc/en/software#ide), instale e execute conforme as instruções no site, baixe o arquivo TecladoViaBluetooth.ino deste projeto e abra na IDE. Plugue o cabo usb no seu pc/notebook e na placa Arduino. Na IDE em Tools/Ferramentas selecione a placa Arduino Leonardo e em Port/Porta selecione a COMx (x é o número que o Windows atribui) ou /dev/ttyUSBy (y é o número que o LInux atribui). Em seguida clique no botão de upload/carregar o programa. 

# App Android
Para desenvolver o APP para Android foi utilizado o site https://appinventor.mit.edu que possui uma interface intuitiva e amigável para desenvolver e prototipar APPs para Android.

Clique no link anterior e faça o cadastro de uma conta para você. Em seguida clique no link da [Galeria de Aplicativos do App Inventor](https://gallery.appinventor.mit.edu/?galleryid=56ef07f5-e61f-4e7a-90a5-a4fdf5190a5d) e baixe o app na sua conta clicando em "Load App Into MIT App Inventor" ou "Load App Into MIT App Inventor". Vai aparecer uma tela com o nome CadastraNFP. Clique nesse nome e em seguida no topo da página procure por Build/Constriur e clique em Android Package (apk). Aguarde a compilação e baixe para seu celular conforme as instruções que vão aparecer na tela. 

# Operação
Após baixar o APP em [Galeria de Aplicativos do App Inventor](https://gallery.appinventor.mit.edu/?galleryid=56ef07f5-e61f-4e7a-90a5-a4fdf5190a5d) basta instalar no Celular Android. Forneça as permissões de uso da câmera e autorize fontes desconhecidas. Rode as rotinas de scan do seu aparelho para garantir a segurança. Este aplicativo NÃO coleta estatísticas ou dados de uso.

Considerando que o hardware já foi construído, ligue o harware no seu note e faça o pareamento do bluetooth do seu celular com o TECLADONFP.

Abra o APP e clique no botão de baixo para conectar no disposivo correto. Na lista que vai aparecer procure por TECLADONFP ou o nome que você utilizou.

Abra o site da [Nota Fiscal Paulista](https://www.nfp.fazenda.sp.gov.br/Inicio.aspx) e vá em Entidades -> Cadastrar Cupons. Na interface de entrada de cupons clique no campo chave de acesso e deixe o mouse posicionado no início desse campo. Após ler um QRCODE o mesmo será enviado para o notebook e se o mouse estiver posicionado no local correto o próximo código já pode ser lido, acelerando o processo.

## Bons cadastros.
