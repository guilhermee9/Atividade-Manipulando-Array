/*
Título: Atividade: Manipulando Array
Autor: Guilherme Gonçalves da Silva   
Data: 23/10/2024
*/


#include <iostream>
#include <string>
#include <algorithm>  // Para usar a função sort()
#include <limits>     // Para usar numeric_limits

using namespace std;

// Função para aguardar que o usuário pressione Enter
void esperarEnter() {
    cout << "\nPressione Enter para continuar...";
    //cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Limpa o buffer de entrada - NO CASO DE DAR ERRO DURANTE A EXECUSSÃO DESCOMENTE ESSA LINHA
    cin.get();  // Aguarda o usuário pressionar Enter
}


// Função para limpar o buffer e resetar o estado do `cin`
void limparBuffer() {
    cin.clear();  // Limpa o estado de erro
    cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignora entradas inválidas no buffer
}

// Função genérica para exibir mensagens de erro
void exibirMensagemErro(const string &mensagem) {
    cout << mensagem << endl;
}

// Função para ler uma string válida
string lerEntradaValida(const string &mensagem) {
    string entrada;
    cout << mensagem;
    getline(cin, entrada);  // Usa getline para aceitar entradas com espaços
    return entrada;
}

// Função para zerar o array de nomes
void zerarArray(string array[], int tamanho) {
    fill(array, array + tamanho, "");  // Usa a função fill para preencher o array com strings vazias
    cout << "Array de nomes zerado!";
    esperarEnter();  // Espera o usuário pressionar Enter
}

// Função para mostrar o array de nomes
void mostrarArray(string array[], int tamanho) {
    cout << "Conteúdo do array de nomes:\n";
    for (int i = 0; i < tamanho; i++) {
        cout << "Posição [" << i << "]: " << array[i] << endl;  // Exibe o índice e o nome
    }
    esperarEnter();  // Espera o usuário pressionar Enter
}

// Função para preencher o array de nomes com entradas do usuário
void preencherArray(string array[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        array[i] = lerEntradaValida("Digite um nome para a posição [" + to_string(i) + "]: ");
    }
    cout << "Array de nomes preenchido manualmente!";
    esperarEnter();  // Espera o usuário pressionar Enter
}

// Função para editar um nome em uma posição específica do array
void editarArray(string array[], int tamanho) {
    int posicao = stoi(lerEntradaValida("Digite a posição que deseja editar (0 a " + to_string(tamanho - 1) + "): "));

    // Garante que a posição esteja dentro dos limites do array
    while (posicao < 0 || posicao >= tamanho) {
        exibirMensagemErro("Posição inválida! Tente novamente.");
        posicao = stoi(lerEntradaValida("Digite uma posição válida: "));
    }

    string nome = lerEntradaValida("Digite o novo nome para a posição [" + to_string(posicao) + "]: ");
    array[posicao] = nome;  // Atualiza o nome na posição escolhida
    cout << "Nome alterado com sucesso!";
    esperarEnter();  // Espera o usuário pressionar Enter
}

// Função para verificar se um nome está presente no array
void verificarNome(string array[], int tamanho) {
    string nome = lerEntradaValida("Digite o nome que deseja verificar: ");
    bool encontrado = false;

    // Verifica se o nome está no array
    for (int i = 0; i < tamanho; i++) {
        if (array[i] == nome) {
            cout << "Nome '" << nome << "' encontrado na posição [" << i << "]" << endl;
            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        cout << "Nome '" << nome << "' não encontrado no array." << endl;
    }

    esperarEnter();  // Espera o usuário pressionar Enter
}

// Função para ordenar o array de nomes em ordem alfabética
void ordenarArray(string array[], int tamanho) {
    sort(array, array + tamanho);  // Usa a função sort() para ordenar o array
    cout << "Array de nomes ordenado com sucesso!";
    esperarEnter();  // Espera o usuário pressionar Enter
}

// Função para contar e mostrar a quantidade de nomes vazios e preenchidos
void mostrarNomesVazios(string array[], int tamanho) {
    int vazios = 0, preenchidos = 0;

    for (int i = 0; i < tamanho; i++) {
        if (array[i].empty()) {  //se array indice estiver empty, incremente vazios, senao incremente preenchidos
            vazios++;
        } else {
            preenchidos++;
        }
    }

    cout << "Quantidade de posições vazias: " << vazios << endl;
    cout << "Quantidade de posições preenchidas: " << preenchidos << endl;
    esperarEnter(); 
}

void contarNomes(string array[], int tamanho) {
    string nome = lerEntradaValida("Digite o nome que deseja contar: ");
    int ocorrencias = 0; //inicia contador ocorrencias em zero

    for (int i = 0; i < tamanho; i++) {
        if (array[i] == nome) {  // verificar se nome do indice é igual da array
            ocorrencias++; //incrementa contador de ocorrencias
        }
    }

    cout << "\nO nome '" <<nome<< "' aparece " <<ocorrencias<< " vez(es) no array." << endl;
    esperarEnter(); 
}

// exibir o nome mais curto e o nome mais longo
void exibirNomePorTamanho(string array[], int tamanho) {
    if (tamanho == 0) {
        cout << "Array está vazio." << endl;
        return;
    }

    string nomeMaisCurto = array[0], nomeMaisLongo = array[0];

    for (int i = 1; i < tamanho; i++) {
        if (array[i].size() < nomeMaisCurto.size()) {
            nomeMaisCurto = array[i];
        }
        if (array[i].size() > nomeMaisLongo.size()) {
            nomeMaisLongo = array[i];
        }
    }

    cout << "Nome mais curto: \"" << nomeMaisCurto << "\" (" << nomeMaisCurto.size() << " caracteres)" << endl;
    cout << "Nome mais longo: \"" << nomeMaisLongo << "\" (" << nomeMaisLongo.size() << " caracteres)" << endl;
    esperarEnter(); 
}

// preencher um array de strings com nomes aleatórios
void preencherNomesAleatorios(string array[], int tamanho) {
    //biblioteca de nomes que serão usados
    string bibliotecaDeNomes[10] = {
        "Ana", "Guilherme", "Mateus", "Daniela", "Vitoria ", 
        "Fernanda", "Gustavo", "Helena", "Luan ", "João"
    };

    // Preenche o array com nomes aleatórios da biblioteca
    for (int i = 0; i < tamanho; i++) {
        array[i] = bibliotecaDeNomes[rand() % 10];  // Escolhe um nome aleatório da lista
    }

    cout << "Array preenchido com nomes aleatórios!" << endl;
    esperarEnter(); 
}




// Função que exibe o menu e retorna a escolha do usuário
int menu() {
    cout << "\nEscolha uma opção:\n";
    cout << "1 - Mostrar array de nomes\n";
    cout << "2 - Zerar array de nomes\n";
    cout << "3 - Preencher array de nomes\n";
    cout << "4 - Editar nome no array\n";
    cout << "5 - Verificar se o nome está no array\n";
    cout << "6 - Ordenar array de nomes\n";
    cout << "7 - Mostrar a Quantidade de Nomes Vazios e Preenchidos\n";
    cout << "8 - Contar ocorrencias de cada nome\n";
    cout << "9 - Exibir o Nome Mais Curto e o Nome Mais Longo\n";
    cout << "10 - Preencher o Array com Nomes Aleatórios\n";
    cout << "0 - Sair\n";
    return stoi(lerEntradaValida("Opção: "));
}

int main() {
    const int TAMANHO = 4;  // Define o tamanho do array de nomes
    string array[TAMANHO];  

    int opcao;

    do {
        opcao = menu();  // Mostra o menu e lê a opção do usuário

        switch (opcao) {
            case 1:
                mostrarArray(array, TAMANHO);
                break;
            case 2:
                zerarArray(array, TAMANHO);
                break;
            case 3:
                preencherArray(array, TAMANHO);
                break;
            case 4:
                editarArray(array, TAMANHO);
                break;
            case 5:
                verificarNome(array, TAMANHO);
                break;
            case 6:
                ordenarArray(array, TAMANHO);
                break;
            case 7:
                mostrarNomesVazios(array, TAMANHO);
            break;
            case 8:
                contarNomes(array, TAMANHO);
            break;
            case 9:
                exibirNomePorTamanho(array, TAMANHO);
            break;
            case 10:
            preencherNomesAleatorios(array, TAMANHO);
            break;
            case 0:
                cout << "Saindo do programa..." << endl;
                break;
            default:
                exibirMensagemErro("Opção inválida! Escolha uma opção válida.");
                break;
        }
    } while (opcao != 0);  // O programa continua executando até que o usuário escolha sair

    return 0;
}
