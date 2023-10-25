#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Paciente {
private:
    string CPF;
    string Nome;
    int Idade;

public:
    Paciente(const string& CPF, const string& Nome, int Idade)
        : CPF(CPF), Nome(Nome), Idade(Idade) {}

    const string& getCPF() const { return CPF; }
    const string& getNome() const { return Nome; }
    int getIdade() const { return Idade; }

    void setNome(const string& novoNome) { Nome = novoNome; }
    void setIdade(int novaIdade) { Idade = novaIdade; }
};

void IncluirPaciente(vector<Paciente>& pacientes) {
    string CPF, Nome;
    int Idade;
    cin.ignore();
    cout << "CPF: "; getline(cin, CPF);
    cout << "Nome: "; getline(cin, Nome);
    cout << "Idade: "; cin >> Idade;

    Paciente novoPaciente(CPF, Nome, Idade);
    pacientes.push_back(novoPaciente);
    cout << "Paciente incluido com sucesso!" << endl;
}

void ExcluirPaciente(vector<Paciente>& pacientes) {
    string ExcluirCPF;
    cout << "Digite o CPF do Paciente que deseja excluir: "; cin >> ExcluirCPF;

    auto it = remove_if(pacientes.begin(), pacientes.end(),
        [&ExcluirCPF](const Paciente& paciente) { return paciente.getCPF() == ExcluirCPF; });

    if (it != pacientes.end()) {
        pacientes.erase(it, pacientes.end());
        cout << "Paciente excluido com sucesso!" << endl;
    } else {
        cout << "CPF nao encontrado. Nenhum paciente excluido." << endl;
    }
}

void AlterarPaciente(vector<Paciente>& pacientes) {
    string AlterarCPF;
    cout << "Digite o CPF do paciente que deseja alterar: "; cin >> AlterarCPF;

    auto it = find_if(pacientes.begin(), pacientes.end(),
        [&AlterarCPF](const Paciente& paciente) { return paciente.getCPF() == AlterarCPF; });

    if (it != pacientes.end()) {
        cout << "Dados atuais do paciente:" << endl;
        cout << "CPF: " << it->getCPF() << endl;
        cout << "Nome: " << it->getNome() << endl;
        cout << "Idade: " << it->getIdade() << endl;

        char opcao;
        cout << "Deseja alterar o nome do paciente? (S/N): "; cin >> opcao;
        if (opcao == 'S' || opcao == 's') {
            cout << "Informe o novo nome: "; cin.ignore(); string novoNome; getline(cin, novoNome);
            it->setNome(novoNome);
        }

        cout << "Deseja alterar a idade do paciente? (S/N): "; cin >> opcao;
        if (opcao == 'S' || opcao == 's') {
            cout << "Informe a nova idade: "; int novaIdade; cin >> novaIdade;
            it->setIdade(novaIdade);
        }

        cout << "Paciente alterado com sucesso!" << endl;
    } else {
        cout << "CPF nao encontrado." << endl;
    }
}

void ListarPacientes(const vector<Paciente>& pacientes) {
    if (pacientes.empty()) {
        cout << "Nenhum paciente cadastrado." << endl;
    } else {
        cout << "Lista de pacientes:" << endl;
        for (const auto& paciente : pacientes) {
            cout << "CPF: " << paciente.getCPF() << endl;
            cout << "Nome: " << paciente.getNome() << endl;
            cout << "Idade: " << paciente.getIdade() << endl;
            cout << "---------------------------" << endl;
        }
    }
}

int main() {
    vector<Paciente> pacientes;
    int escolha;
    do {
        cout << "\nMenu de Opcoes:" << endl;
        cout << "1. Incluir Paciente" << endl;
        cout << "2. Excluir Paciente" << endl;
        cout << "3. Alterar Paciente (Apenas por CPF)" << endl;
        cout << "4. Listar Pacientes" << endl;
        cout << "0. Sair" << endl;
        cout << "Escolha uma opcao: "; cin >> escolha;

        switch (escolha) {
            case 1: IncluirPaciente(pacientes); break;
            case 2: ExcluirPaciente(pacientes); break;
            case 3: AlterarPaciente(pacientes); break;
            case 4: ListarPacientes(pacientes); break;
            case 0: cout << "Saindo do programa." << endl; break;
            default: cout << "Opcao invalida." << endl;
        }
    } while (escolha != 0);

    return 0;
}