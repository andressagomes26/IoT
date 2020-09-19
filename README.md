<h1 align="center"> 
 Internet of Things | NodeMCU ESP-WROOM-32 | Protocolo MQTT
</h1>

Projetos desenvolvidos para prática de Internet das Coisas (IoT).

## Dependências

- NodeMCU ESP-WROOM-32;
- Sensor LDR (Light Dependent  Resistor);
- Sensor ultrassônico HC-SR04;
- Arduino IDE 1.3.3.

## Sobre o projeto

### Projeto 01

O projeto consiste em registrar na nuvem através do serviço do site ThingSpeak.com dados de distância e luminosidade coletados pelo sensor  ultrassônico HC-SR04 e pelo sensor LDR, respectivamente. Para isso será utilizou-se o NodeMCU ESP-WROOM-32, plataforma open source desenvolvida para projetos de Internet das Coisas. Outrossim, após a análise dos dados  captados  na  nuvem, utilizou-se o recurso Matlab Analysis para calcular a média dos dados obtidos.

### Projeto 02
O MQTT é  um  protocolo  de  mensagens situado  na  camada  de  aplicação e é  um  padrão  aberto  para  comunicação  entre dispositivos. Assim, o projeto consiste em, realizar  a comunicação entre o NodeMCU ESP-WROOM-32 com o broker MQTT, tornando possível controlar o LED conectado na prática a partir do servidor. 

## Autores
- Andressa Gomes Moreira - andressagomes@alu.ufc.br.

## Status do Projeto
O projeto encontra-se em desenvolvimento. 

## Licença
- MIT
