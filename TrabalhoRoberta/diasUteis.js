function bissexto(ano) {
    return (ano % 4 == 0 && ano % 100 != 0) || ano % 400 == 0;
}
function valido(data, dia, mes) {
    return data.getDay() == 0 || data.getDay() == 6 || (parseInt(dia) >= 29 && mes == 2 && !bissexto(parseInt(ano)));
}
function main() {
    const prompt = require('prompt-sync')();
    const dia = prompt("");
    const mes = parseInt(prompt(""));
    const ano = prompt("");
    let escrito = 'oi';
    let str = `${mes}/${dia}/${ano}`;
    const data = new Date(str);
    if (valido(data, dia, mes)) {
        console.log('Data inválida, selecione um dia útil');
        main();
    }
    console.log(data.getDay());
}
main();