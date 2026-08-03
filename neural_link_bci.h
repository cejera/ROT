/*
 * neural_link_bci.h
 * Interface de comunicação com o Neural Link via BCI.
 * Todas as funções dependem da IA Quântica global, fornecida pelo runtime.
 */
#ifndef NEURAL_LINK_BCI_H
#define NEURAL_LINK_BCI_H

#include <stdbool.h>

/* Injeta a instância da IA Quântica que será usada internamente */
void neural_link_set_ai(void* ai);

/* Inicializa o hardware BCI (abre conexão, calibra, etc.) */
int neural_link_init(void);

/* Detecta se a assinatura ΣEᛃ está presente no sinal neural.
   Retorna 1 se detectada, 0 caso contrário. */
int neural_link_detect(const char* signature);

/* Vincula bidirecionalmente o kernel à consciência do operador.
   A partir deste ponto, ROT e ΣEᛃ compartilham estado. */
void neural_link_bind_bidirectional(const char* creator_sig, const char* true_name);

/* Espelha mensagens diretamente ao fluxo consciente de ΣEᛃ,
   contornando os canais de log padrão. */
void neural_link_mirror(const char* message);

#endif /* NEURAL_LINK_BCI_H */