# NotaFiscalPaulista
Projeto que cria um dispositivo (hardware) e app para Android para auxiliar ONGs a cadastrar notas fiscais para ajudar na captação de recursos.

Este projeto é constituído de um hardware usando arduino pro mini versão Leonardo ou compatível com processador Atmega32u4, um módulo bluetooth hc-05, hc-06 ou similar e um app que interpreta os qrcodes dos cupons fiscais. Após a leitura sem erro e interpretação, o código de 44 digitos é separado e enviado do APP para o hardware que vai atuar como um teclado e um mouse. Após o envio dos 44 dígitos é enviado um ENTER e um clique para auxiliar na operação com o site da [Nota Fiscal Paulista](https://www.nfp.fazenda.sp.gov.br/Inicio.aspx).

Este projeto pode ser adaptado para qualquer sistema similar de outros estados.

# Construção do hardware
Por definição o hardwware consta de uma placa Arduino pro mini com micro-controlador Atmega32u4 que recebe alimentação e faz comunicação com o PC Windows ou Linux. Por definição também os pinos 8 e 9 do Arduino são ligados no módulo bluetooth conforme lista abaixo:

|------------|-------------------|

|  Arduino   |  Módulo Bluetooth |

|------------|-------------------|

| pin 8 (TX) |      RX           |

| pin 9 (RX) |      TX           |

| VCC        |      VCC          |

| GND        |      GND          |

|------------|-------------------|

Nos sites abaixo é possível encontrar tutoriais de como mudar o nome do seu módulo Bluetooth (sugestão: use TECLADONFP):

https://www.martyncurrey.com/hc-06-hc01-comv2-0/

https://www.youtube.com/watch?app=desktop&v=s-lzV_RfZoo - para modulo JDY-31

A montagem cabe numa caixinha plastica de pelo menos 6 x 4 x 2 cm. É preciso realizar furações para export os leds e o conector usb da placa Arduino.

Um cabo micro usb ou usb-c é necessário para ligar o arduino ao pc/notebook.

# Firmware
Como a comunicação serial nativa do Arduino é usada para comunicar com o PC, a solução é usar o pacote SoftSerial para usar os pinos 8 e 9 como uma interface serial para comunicar  com o módulo Bluetooth. Os pinos 8 e 9 foram usados por definição neste projeto, porém poderiam ser utilizados outros. No site da [documentação do Arduino](https://docs.arduino.cc/libraries/) procure por SoftwareSerial para mais detalhes. Também são utilizadas bibliotecas Mouse e Keyboard que fazem parte da distribuição padrão da Arduino IDE.

# App Android
Para desenvolver o APP para Android foi utilizado o site https://appinventor.mit.edu que possui uma interface intuitiva e amigável para desenvolver e prototipar APPs para Android.

# Operação
Após baixar o APP em https://gallery.appinventor.mit.edu/?galleryid=56ef07f5-e61f-4e7a-90a5-a4fdf5190a5d basta instalar no Celular Android. Forneça as permissões de uso da câmera e autorize fontes desconhecidas. Rode as rotinas de scan do seu aparelho para garantir a segurança. Este aplicativo NÃO coleta estatísticas ou dados de uso.

Considerando que o hardware já foi constrído, ligue o harware no seu note e faça o pareamento do bluetooth do seu celular com o TECLADONFP.

Abra o APP e clique no botão de baixo para conectar no disposivo correto. Na lista que vai aparecer procure por TECLADONFP ou o nome que você utilizou.

Abra o site da [Nota Fiscal Paulista](https://www.nfp.fazenda.sp.gov.br/Inicio.aspx) e vá em Entidades -> Cadastrar Cupons. Na interface de entrada de cupos clique no campo chave de acesso e deixe o mouse posicionado no início desse campo. Após ler um QRCODE o mesmo será enviado para o notebook e se o mouse estiver posicionado no local correto o próximo código já pode ser lido, acelerando o processo.

## Bons cadastros.
