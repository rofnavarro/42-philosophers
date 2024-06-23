- [English](#english)
- [Português](#português)

# English

# philosophers - 42

This project, philosophers, is part of the curriculum at School 42. The goal of this project is to implement the dining philosophers problem using threads and synchronization mechanisms such as mutexes and semaphores.

## Table of Contents

- [Introduction](#introduction)
- [Problem Statement](#problem-statement)
- [How to Run](#how-to-run)

## Introduction

The philosophers project is a classic concurrency problem known as the dining philosophers problem. It involves a group of philosophers sitting at a table with a bowl of spaghetti and forks between each pair of adjacent philosophers. The philosophers alternate between thinking and eating but require two forks to eat. The challenge is to prevent deadlock and starvation while allowing the philosophers to eat as efficiently as possible.

## Problem Statement

The philosophers project involves the following aspects:

1. Implement a program that simulates the dining philosophers problem.
2. Create a configurable number of philosophers and forks.
3. Use threads to represent philosophers and synchronization mechanisms to handle access to forks.
4. Prevent deadlock and starvation using appropriate synchronization techniques.
5. Ensure that each philosopher alternates between thinking, picking up forks, eating, and putting down forks.

## How to Run

To run the philosophers program, follow these steps:

1. Clone the philosophers repository:
   ```sh
   git clone git@github.com:rofnavarro/42-philosophers.git
   cd 42-philosophers/philo
   ```

2. Compile the program:
   ```sh
   make
   ```

3. Run the philosophers program with the desired number of philosophers and simulation time:
   ```sh
   ./philo [number_of_philosophers] [time_to_simulation_end] [time_to_die] [time_to_eat] [time_to_sleep]
   ```
   Replace `[number_of_philosophers]` with the desired number of philosophers and adjust the other parameters as needed.

***

# Português

# philosophers - 42

Este projeto, philosophers, faz parte do currículo da Escola 42. O objetivo deste projeto é implementar o problema dos filósofos jantando usando threads e mecanismos de sincronização como mutexes e semáforos.

## Sumário

- [Introdução](#introdução)
- [Descrição do Problema](#descrição-do-problema)
- [Como Executar](#como-executar)

## Introdução

O projeto philosophers é um problema clássico de concorrência conhecido como o problema dos filósofos jantando. Ele envolve um grupo de filósofos sentados em uma mesa com uma tigela de espaguete e garfos entre cada par de filósofos adjacentes. Os filósofos alternam entre pensar e comer, mas precisam de dois garfos para comer. O desafio é evitar o deadlock e a inanição, permitindo que os filósofos comam de forma eficiente.

## Descrição do Problema

O projeto philosophers envolve os seguintes aspectos:

1. Implementar um programa que simule o problema dos filósofos jantando.
2. Criar um número configurável de filósofos e garfos.
3. Usar threads para representar os filósofos e mecanismos de sincronização para controlar o acesso aos garfos.
4. Evitar o deadlock e a inanição usando técnicas apropriadas de sincronização.
5. Garantir que cada filósofo alterne entre pensar, pegar garfos, comer e colocar garfos.

## Como Executar

Para executar o programa philosophers, siga estas etapas:

1. Clone o repositório philosophers:
   ```sh
   git clone git@github.com:rofnavarro/42-philosophers.git
   cd 42-philosophers/philo
   ```

2. Compile o programa:
   ```sh
   make
   ```

3. Execute o programa philosophers com o número desejado de filósofos e o tempo de simulação:
   ```sh
   ./philo [número_de_filósofos] [tempo_de_simulação] [tempo_para_morrer] [tempo_para_comer] [tempo_para_dormir]
   ```
   Substitua `[número_de_filósofos]` pelo número desejado de filósofos e ajuste os outros parâmetros conforme necessário.
