#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Medico {
private:
    string CRM;
    string Nome;
    string Especialidade;

public:
    Medico(const string& CRM, const string& Nome, const string& Especialidade)
        : CRM(CRM), Nome(Nome), Especialidade(Especialidade) {}

    const string& getCRM() const { return CRM; }
    const string& getNome() const { return Nome; }
    const string& getEspecialidade() const { return Especialidade; }

    void setNome(const string& novoNome) { Nome = novoNome; }
    void setEspecialidade(const string& novaEspecialidade) { Especialidade = novaEspecialidade; }
};

void IncluirMedico(vector<Medico>& medicos) {
    string CRM, Nome, Especialidade;
    cin.ignore();
    cout << "CRM: "; getline(cin, CRM);
    cout << "Nome: "; getline(cin, Nome);
    cout << "Especialidade: "; getline(cin, Especialidade);

    Medico novoMedico(CRM, Nome, Especialidade);
    medicos.push_back(novoMedico);
    cout << "Medico incluido com sucesso!" << endl;
}

void ExcluirMedico(vector<Medico>& medicos) {
    string ExcluirCRM;
    cout << "Digite o CRM do Medico que deseja excluir: "; cin >> ExcluirCRM;

    auto it = remove_if(medicos.begin(), medicos.end(),
        [&ExcluirCRM](const Medico& medico) { return medico.getCRM() == ExcluirCRM; });

    if (it != medicos.end()) {
        medicos.erase(it, medicos.end());
        cout << "Medico excluido com sucesso!" << endl;
    } else {
        cout << "CRM nao encontrado. Nenhum medico excluido." << endl;
    }
}

void AlterarMedico(vector<Medico>& medicos) {
    string AlterarCRM;
    cout << "Digite o CRM do medico que deseja alterar: "; cin >> AlterarCRM;

    auto it = find_if(medicos.begin(), medicos.end(),
        [&AlterarCRM](const Medico& medico) { return medico.getCRM() == AlterarCRM; });

    if (it != medicos.end()) {
        cout << "Dados atuais do medico:" << endl;
        cout << "CRM: " << it->getCRM() << endl;
        cout << "Nome: " << it->getNome() << endl;
        cout << "Especialidade : " << it->getEspecialidade() << endl;

        char opcao;
        cout << "Deseja alterar o nome do medico? (S/N): "; cin >> opcao;
        if (opcao == 'S' || opcao == 's') {
            cout << "Informe o novo nome: "; cin.ignore(); string novoNome; getline(cin, novoNome);
            it->setNome(novoNome);
        }

        cout << "Deseja alterar a especialidade do medico? (S/N): "; cin >> opcao;
        if (opcao == 'S' || opcao == 's') {
            cout << "Informe a nova Especialidade: "; cin.ignore(); string novaEspecialidade; getline(cin, novaEspecialidade);
            it->setEspecialidade(novaEspecialidade);
        }

        cout << "Medico alterado com sucesso!" << endl;
    } else {
        cout << "CRM nao encontrado." << endl;
    }
}

void ListarMedicos(const vector<Medico>& medicos) {
    if (medicos.empty()) {
        cout << "Nenhum medico cadastrado." << endl;
    } else {
        cout << "Lista de medicos:" << endl;
        for (const auto& medico : medicos) {
            cout << "CRM: " << medico.getCRM() << endl;
            cout << "Nome: " << medico.getNome() << endl;
            cout << "Especialidade: " << medico.getEspecialidade() << endl;
            cout << "---------------------------" << endl;
        }
    }
}

int main() {
    vector<Medico> medicos;
    int escolha;
    do {
        cout << "\nMenu de Opcoes:" << endl;
        cout << "1. Incluir Medico" << endl;
        cout << "2. Excluir Medico" << endl;
        cout << "3. Alterar Medico (Apenas por CRM)" << endl;
        cout << "4. Listar Medicos" << endl;
        cout << "0. Sair" << endl;
        cout << "Escolha uma opcao: "; cin >> escolha;

        switch (escolha) {
            case 1: IncluirMedico(medicos); break;
            case 2: ExcluirMedico(medicos); break;
            case 3: AlterarMedico(medicos); break;
            case 4: ListarMedicos(medicos); break;
            case 0: cout << "Saindo do programa." << endl; break;
            default: cout << "Opcao invalida." << endl;
        }
    } while (escolha != 0);

    return 0;
}