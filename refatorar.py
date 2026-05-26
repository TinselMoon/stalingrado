import os

def refatorar_raiz():
    base_dir = "stalingrado"
    
    # Ignoramos os arquivos principais porque eles já possuem o namespace
    ignorar = ["Stalingrad.hpp", "Stalingrad.cpp"]

    for root, dirs, files in os.walk(base_dir):
        for file in files:
            if not (file.endswith('.hpp') or file.endswith('.cpp')):
                continue
            if file in ignorar:
                continue

            filepath = os.path.join(root, file)
            
            with open(filepath, 'r', encoding='utf-8') as f:
                content = f.read()

            # Evita envelopar o código duas vezes caso rode o script por engano
            if "namespace Stalingrado {" in content:
                continue

            lines = content.split('\n')
            insert_idx = 0
            
            # Encontra a última linha de dependências (#include, #pragma ou #define)
            for i, line in enumerate(lines):
                stripped = line.strip()
                if stripped.startswith('#include') or stripped.startswith('#pragma') or stripped.startswith('#define'):
                    insert_idx = i + 1

            # Monta o novo conteúdo colocando o namespace logo após os includes
            new_content = '\n'.join(lines[:insert_idx])
            new_content += '\n\nnamespace Stalingrado {\n'
            new_content += '\n'.join(lines[insert_idx:])
            new_content += '\n} // Fim do namespace Stalingrado\n'

            with open(filepath, 'w', encoding='utf-8') as f:
                f.write(new_content)

    print("✅ Script finalizado! Todos os arquivos foram colocados no namespace Stalingrado.")

if __name__ == "__main__":
    refatorar_raiz()
