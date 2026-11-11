use arma_rs::{FromArma, FromArmaError};

#[derive(Debug, PartialEq, Eq)]
pub struct Raw(pub String);

impl FromArma for Raw {
    fn from_arma(value: String) -> Result<Self, FromArmaError> {
        Ok(Self(value))
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn preserves_quotes_and_empty_strings() {
        let value = r#"[""save"",[""name"",""""]]"#;
        assert_eq!(Raw::from_arma(value.to_owned()), Ok(Raw(value.to_owned())));
    }
}
