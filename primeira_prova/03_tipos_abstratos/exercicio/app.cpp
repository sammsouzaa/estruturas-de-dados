#include <iostream>
#include <string>
#include <cstdlib> // Para o rand()
#include <ctime>   // Para inicializar a semente do rand()
using namespace std;

class ContaBancaria{

    private:
        int id_conta;
        float saldo;
        string nome;
        string cpf;
        string tipo_conta;
        bool status_conta;
        int senha;

        bool VerificarContaExiste(){ return id_conta != 0 ? true : false;}

        bool verificarStatusConta(){ return status_conta == false ? false : true;}

        int GerarNumeroConta(){
            int numero = rand() % 10000;
            if(numero == 0) numero = 1;
            return numero;
        }

        float verificarSaldoConta(){
            return this->saldo;
        }

        void CriarContaBancaria(string novo_nome, string novo_cpf, string novo_tipo, int nova_senha){
            this->id_conta = this->GerarNumeroConta();
            this->saldo = 0;
            this->nome = novo_nome;
            this->cpf = novo_cpf;
            this->tipo_conta = novo_tipo;
            this->status_conta = true; // Conta fica ativa
            this->senha = nova_senha;
        }

    public:

        // Construtor vazio
        ContaBancaria (){
            this->id_conta = 0; // Inicializa em 0 para indicar que nao foi criada ainda
            this->saldo = 0;
            this->status_conta = false;
        }

        // Construtor com dados
        ContaBancaria (int id_conta, float saldo, string nome, string cpf, string tipo_conta, bool status_conta, int senha){
            this->id_conta = id_conta;
            this->saldo = saldo;
            this->nome = nome;
            this->cpf = cpf;
            this->tipo_conta = tipo_conta;
            this->status_conta = status_conta;
            this->senha = senha;
        }

        // Interface publica do sistema
        void criarContaBancaria(){
            string input_nome, input_cpf, input_tipo;
            int input_senha;

            cout << "Digite o nome: ";
            cin >> input_nome;
            cout << "Digite o cpf: ";
            cin >> input_cpf;
            cout << "Digite o tipo da conta (ex: Corrente): ";
            cin >> input_tipo;
            cout << "Digite a senha (numerica): ";
            cin >> input_senha;

            this->CriarContaBancaria(input_nome, input_cpf, input_tipo, input_senha);
            cout << "\n[Sucesso] Conta criada! O seu numero de conta e: " << this->id_conta << "\n\n";
        }

        void Consultar_Saldo(){
            if(VerificarContaExiste() && verificarStatusConta()) {
                cout << "=> Saldo Atual: R$ " << verificarSaldoConta() << "\n\n";
            } else {
                cout << "Erro: Conta nao existe ou esta inativa.\n\n";
            }
        }

        void Sacar(float valor){
            if(!VerificarContaExiste() || !verificarStatusConta()){
                cout << "Erro: Conta nao existe ou esta inativa.\n";
                return;
            }

            if(valor > saldo){
                cout << "[Operacao Negada] Saldo insuficiente para sacar R$ " << valor << "\n";
            } else if (valor <= 0){
                cout << "[Operacao Negada] Valor invalido para saque.\n";
            } else {
                saldo -= valor;
                cout << "[Sucesso] Voce sacou R$ " << valor << "\n";
            }
        }

        void Depositar(float valor){
            if(!VerificarContaExiste() || !verificarStatusConta()){
                cout << "Erro: Conta nao existe ou esta inativa.\n";
                return;
            }

            if(valor <= 0){
                cout << "[Operacao Negada] Valor invalido para deposito.\n";
            } else {
                saldo += valor;
                cout << "[Sucesso] Voce depositou R$ " << valor << "\n";
            }
        }

        void Verificar_Status(){
            if (verificarStatusConta()){
                cout << "Status: Conta Ativa\n";
            } else {
                cout << "Status: Conta Inativa\n";
            }
        }    
};

int main () {
    // Inicializa a semente para o numero randomico
    srand(time(NULL));

    cout << "=== BEM VINDO AO BANCO TAD ===" << endl;

    // Criamos o objeto "em branco"
    ContaBancaria minha_conta;
    
    // Criamos os dados da conta interagindo com o usuario
    minha_conta.criarContaBancaria();

    // Verificamos se o saldo comeca zerado
    minha_conta.Consultar_Saldo();

    // Depositamos 500 reais
    minha_conta.Depositar(500.50);
    minha_conta.Consultar_Saldo();

    // Tentamos sacar 1000 reais (deve ser bloqueado pelo TAD)
    minha_conta.Sacar(1000.0);

    // Sacamos 200 reais com sucesso
    minha_conta.Sacar(200.0);
    minha_conta.Consultar_Saldo();

    return 0;
}