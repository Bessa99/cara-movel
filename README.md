# 🚗💥 Cará-Móvel

> Carrinho com torreta Nerf controlado via Bluetooth — Projeto Final de Introdução ao Hardware  
> **Grupo Cin-Cará | CIn-UFPE | 2026.1**

---

## 📋 Descrição

O **Cará-Móvel** é um veículo de controle remoto desenvolvido com Arduino, capaz de:

- 🚗 Se movimentar para **frente, ré e realizar curvas**
- 🎯 Girar uma **torreta** via servo motor
- 💥 **Disparar dardos Nerf** pelo mecanismo da torreta
- 📱 Ser controlado via **Bluetooth pelo celular**

A ideia surgiu da inspiração em um tanque de guerra em escala reduzida, adaptada aos materiais disponíveis no laboratório de hardware do CIn-UFPE.

---

## 👥 Integrantes

| Nome | Login |
|------|-------|
| João Daniel de Mélo Miranda | jdmm |
| João Lucas Gomes da Silva | jlgs2 |
| João Lucas Tavares Cavalcanti | jltc |
| Marcelo Guilherme de Barros Hermínio | mgbh |
| André Bessa da Costa | abc5 |
| Ewerton Manoel Fernandes | emflc |
| Rafael Gonçalves | rglc |

---

## 🔧 Componentes

| Componente | Qtd. | Função |
|-----------|------|--------|
| Kit Chassi (4 rodas) | 1 | Estrutura mecânica |
| Arduino Nano | 2 | Controle de locomoção e torreta |
| Módulo Bluetooth (HC-05/06) | 1 | Comunicação com o celular |
| Ponte H (L298N) | 1 | Controle dos motores DC |
| Motor DC 12V | 2 | Tração principal |
| Motor DC 3–6V | 2 | Rodas auxiliares |
| Servo Motor | 1 | Rotação da torreta e disparo |
| Protoboard | 1 | Montagem dos circuitos |
| Kit de Jumpers | 1 kit | Conexões |
| Dardos Nerf | 1 pack | Projéteis |

---

## 📁 Estrutura do Repositório

```
cara-movel/
├── locomocao/
│   └── locomocao.ino       # Código do Arduino de locomoção
├── torreta/
│   └── torreta.ino         # Código do Arduino da torreta
├── circuitos/
│   └── (inserir esquemas dos circuitos aqui)
├── fotos/
│   └── (inserir fotos da montagem aqui)
└── README.md
```

---

## ⚙️ Como Funciona

### Locomoção
O Arduino de locomoção recebe comandos via Bluetooth e aciona a Ponte H para controlar os 4 motores DC:

| Comando | Ação |
|---------|------|
| `F` | Frente |
| `B` | Ré |
| `L` | Esquerda |
| `R` | Direita |
| `S` | Parar |

### Torreta
O segundo Arduino controla o servo motor e o mecanismo de disparo:

| Comando | Ação |
|---------|------|
| `A` | Girar torreta à esquerda |
| `D` | Girar torreta à direita |
| `T` | Disparar dardo Nerf |

---

## 📱 Controle

O controle é feito via aplicativo Bluetooth no celular, que envia caracteres seriais interpretados pelos Arduinos.

---

## 📚 Referências

- [MONTE UM CANHÃO NERF COM ARDUINO!](https://www.youtube.com/watch?v=GO-HQm2UU1E)
- [How to build a 3D printed Arduino Nerf turret - Part 1](https://www.youtube.com/watch?v=LdfZEvabwI0)
- [How to build a 3D printed Arduino Nerf turret - Part 2](https://www.youtube.com/watch?v=SIL-A4abX7k)
- [How to build a 3D printed Arduino Nerf turret - Part 3](https://www.youtube.com/watch?v=WR17Wdy998s)

---

> CIn-UFPE · Introdução ao Hardware · 2025.1
