@ECHO OFF
setlocal DISABLEDELAYEDEXPANSION
SET BIN_TARGET=%~dp0/../pradosoft/prado/bin/prado-cli
php "%BIN_TARGET%" %*
