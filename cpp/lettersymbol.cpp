#include "lettersymbol.h"

LetterSymbol::LetterSymbol(QObject *parent) :
    QObject(parent)
{
    m_Maps["Morsecode"] = &m_MorseCode;

    m_MorseCode["a"] = ".-";
    m_MorseCode["b"] = "-...";
    m_MorseCode["c"] = "-.-.";
    m_MorseCode["d"] = "-..";
    m_MorseCode["e"] = ".";
    m_MorseCode["f"] = "..-.";
    m_MorseCode["g"] = "--.";
    m_MorseCode["h"] = "....";
    m_MorseCode["i"] = "..";
    m_MorseCode["j"] = ".---";
    m_MorseCode["k"] = "-.-";
    m_MorseCode["l"] = ".-..";
    m_MorseCode["m"] = "--";
    m_MorseCode["n"] = "-.";
    m_MorseCode["o"] = "---";
    m_MorseCode["p"] = ".--.";
    m_MorseCode["q"] = "--.-";
    m_MorseCode["r"] = ".-.";
    m_MorseCode["s"] = "...";
    m_MorseCode["t"] = "-";
    m_MorseCode["u"] = "..-";
    m_MorseCode["v"] = "...-";
    m_MorseCode["w"] = ".--";
    m_MorseCode["x"] = "-..-";
    m_MorseCode["y"] = "-.--";
    m_MorseCode["z"] = "--..";
}

QString LetterSymbol::toLetter(QString symbol, QString List)
{
    QString ReturnLetter;
    QString NotFound(" ");
    if(m_Maps.contains(List))
    {
        if(m_Maps[List]->key(symbol) != NotFound)
        {
            ReturnLetter = m_Maps[List]->key(symbol);
        }
    }
    return ReturnLetter;
}

QString LetterSymbol::toSymbol(QString letter, QString List)
{
    QString ReturnLetter;
    if(m_Maps.contains(List))
    {
        if(m_Maps[List]->contains(letter))
        {
            ReturnLetter = m_Maps[List]->value(letter);
        }
    }
    return ReturnLetter;
}
