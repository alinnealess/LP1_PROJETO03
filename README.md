# IMDCorp system extended project

## Dados acadêmicos
- Ver detalhes: [pt-BR](./docs/academic_data_pt-BR.md), [en-GB](./docs/academic_data_en-GB.md)

## Instruções de uso
Para utilizar este programa, é necessário ter ambiente configurado com o compilador g++, de C++, além dos pacotes linux `build-essential` e `make`.

Após ter o compilador instalado, e ter extraído os arquivos deste repositório para um diretório na sua máquina, basta:

1. Abrir um terminal
2. Executar `make` no diretório raíz em que o projeto estiver
3. O programa será automaticamente compilado e será executado
4. O menu principal (perfil único) será apresentado

### Menu de usuário único
Neste menu você poderá realizar as seguintes operações de gerenciamento de professores e técnico-administrativos do IMDCorp: cadastrar, listar e excluir. Além disso, poderá escolher opção de sair do programa.

Todas estas operações utilizam e atualizam o arquivo fonte dos dados que se encontra no subdiretório `./data` do programa.
