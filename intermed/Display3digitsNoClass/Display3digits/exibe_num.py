def exibe(numero):
    for pos in range(3):
        resto = numero % 10
        numero /= 10
        print pos, '->', numero, resto
        if numero == 0: break


